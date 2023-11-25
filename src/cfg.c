#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "cfg.h"

#define CONTROL_FLOW_BUFF_STEP 10
#define MAX_BLOCK_ID 999999
#define MAX_BLOCK_ID_LEN 6
#define DOT_BLOCK_DEFINITION_SYNTAX_LEN 13
#define DOT_CONTROL_DEFINITION_SYNTAX_LEN 27
#define DOT_BLOCK_CONNECTION_SYNTAX_LEN 5
#define DOT_END_BLOCK_DEFINITION_SYNTAX_LEN 25
#define DOT_SUBPROGRAM_BASE_DEFINITION_LEN 92

ControlFlow* create_control_flow() {
  ControlFlow* cf = malloc(sizeof(ControlFlow));
  cf->size = CONTROL_FLOW_BUFF_STEP;
  cf->length = 0;
  cf->subprograms = malloc(CONTROL_FLOW_BUFF_STEP * sizeof(Subprogram*));
  return cf;
}

void _destroy_block(Block* block) {
  if (!block) return;
  switch (block->type) {
    case BLOCK_ACTION:
      ActionBlockInfo* action_info = (ActionBlockInfo*)block->info;
      _destroy_block(action_info->next);
      free(action_info);
      break;
    case BLOCK_LOOP:
      LoopBlockInfo* loop_info = (LoopBlockInfo*)block->info;
      _destroy_block(loop_info->body);
      _destroy_block(loop_info->next);
      free(loop_info);
      break;
    case BLOCK_CONDITION:
      ConditionBlockInfo* condition_info = (ConditionBlockInfo*)block->info;
      _destroy_block(condition_info->if_body);
      _destroy_block(condition_info->else_body);
      _destroy_block(condition_info->next);
      free(condition_info);
      break;
  }
  free(block->value);
  free(block);
}

void _destroy_subprogram(Subprogram* subp) {
  if (!subp) return;
  _destroy_block(subp->start);
  free(subp->name);
  free(subp->filename);
  free(subp);
}

void destroy_control_flow(ControlFlow* cf) {
  if (!cf) return;
  for (int i = 0; i < cf->length; i++) {
    _destroy_subprogram(cf->subprograms[i]);
  }
  free(cf);
}

void control_flow_push(ControlFlow* cf, Subprogram* subprogram) {
  assert(cf->length <= cf->size);
  if (cf->length == cf->size) {
    cf->size += CONTROL_FLOW_BUFF_STEP;
    cf->subprograms = realloc(cf->subprograms, cf->size * sizeof(Subprogram*));
  }
  cf->subprograms[cf->length++] = subprogram;
}

Block* _create_start_action_block();

Subprogram* _create_subprogram(AstNode* subp_node, char* filename) {
  /* Node = SourceItem with body */
  Subprogram* subp = malloc(sizeof(Subprogram));
  subp->start = _create_start_action_block();
  subp->name = strdup(subp_node->left->value);
  subp->filename = strdup(filename);
  return subp;
}

unsigned int _generate_new_block_id() {
  static unsigned int counter = 1;
  if (counter > MAX_BLOCK_ID) counter = 1;
  return counter++;
}

Block* _create_blocks_chain(Block* current_block, AstNode* list_node) ;

Block* _create_start_action_block() {
  Block* block = malloc(sizeof(Block));
  block->id = _generate_new_block_id();
  block->type = BLOCK_ACTION;
  block->value = NULL;

  ActionBlockInfo* info = malloc(sizeof(ActionBlockInfo));
  block->info = info;
  info->prev = NULL;
  info->next = NULL;
  return block;
}

void _block_add_next(Block* block, Block* next_block) {
  switch (block->type) {
    case BLOCK_ACTION:
      ActionBlockInfo* action_info = (ActionBlockInfo*)block->info;
      action_info->next = next_block;
      break;
    case BLOCK_LOOP:
      LoopBlockInfo* loop_info = (LoopBlockInfo*)block->info;
      loop_info->next = next_block;
      break;
    case BLOCK_CONDITION:
      ConditionBlockInfo* condition_info = (ConditionBlockInfo*)block->info;
      condition_info->next = next_block;
      break;
  }
}

Block* _create_end_action_block(Block* previous_block) {
  Block* block = malloc(sizeof(Block));
  block->id = _generate_new_block_id();
  block->type = BLOCK_ACTION;
  block->value = NULL;

  ActionBlockInfo* info = malloc(sizeof(ActionBlockInfo));
  block->info = info;
  info->prev = previous_block;
  _block_add_next(previous_block, block);
  info->next = NULL;
  return block;
}

char* _get_expr_node_name(AstNode* node) {
  /* Node = expr or Node = token */
  char* value = strdup(node->name);
  char* l_operand = NULL;
  char* r_operand = NULL;
  if (node->left) {
    l_operand = _get_expr_node_name(node->left);
  }
  if (node->right) {
    r_operand = _get_expr_node_name(node->right);
  }
  
  /* Presence of right operand means that left also exists */
  if (r_operand) {
    char* name = malloc(sizeof(char) * (strlen(value) + strlen(l_operand) + strlen(r_operand) + 7));
    sprintf(name, "%s ( %s %s )", value, l_operand, r_operand);
    free(value);
    free(l_operand);
    free(r_operand);
    return name;
  }
  if (l_operand) {
    char* name = malloc(sizeof(char) * (strlen(value) + strlen(l_operand) + 6));
    sprintf(name, "%s ( %s )", value, l_operand);
    free(value);
    free(l_operand);
    return name;
  };
  return strdup(node->value);
}

Block* _block_create_next_action(Block* block, AstNode* node) {
  /* Node = expression */
  Block* next_block = malloc(sizeof(Block));
  next_block->id = _generate_new_block_id();
  next_block->type = BLOCK_ACTION;
  next_block->value = _get_expr_node_name(node->left);
   
  ActionBlockInfo* next_info = malloc(sizeof(ActionBlockInfo));
  next_block->info = next_info;
  next_info->prev = block;
  next_info->next = NULL;
  _block_add_next(block, next_block);
  return next_block;
}

Block* _block_create_next_loop(Block* block, AstNode* node) {
  /* Node = while or Node = do */
  Block* next_block = malloc(sizeof(Block));
  next_block->id = _generate_new_block_id();
  next_block->type = BLOCK_LOOP;
  next_block->value = _get_expr_node_name(node->left);
  
  LoopBlockInfo* next_info = malloc(sizeof(LoopBlockInfo));
  next_block->info = next_info;
  next_info->prev = block;

  /* Pass Node = listStatement which is instructions inside loop,
   * also we need to get first block in chain from loop block
   * itself, because create_blocks returns last block in the chain */
  _create_blocks_chain(next_block, node->right);
  next_info->body = next_info->next;
  next_info->next = NULL;
  _block_add_next(block, next_block);
  return next_block;
}

Block* _block_create_next_condition(Block* block, AstNode* node) {
  /* Node = if */
  Block* next_block = malloc(sizeof(Block));
  next_block->id = _generate_new_block_id();
  next_block->type = BLOCK_CONDITION;
  next_block->value = _get_expr_node_name(node->left);
  
  ConditionBlockInfo* next_info = malloc(sizeof(ConditionBlockInfo));
  next_block->info = next_info;
  next_info->prev = block;
  _create_blocks_chain(next_block, node->right->left);
  next_info->if_body = next_info->next;

  /* Check on if block has else statement */
  if (node->right->right) {
    _create_blocks_chain(next_block, node->right->right->left);
    next_info->else_body = next_info->next;
  }
  else {
    next_info->else_body = NULL;
  }
  next_info->next = NULL;
  _block_add_next(block, next_block);
  return next_block;
}

Block* _create_blocks_chain(Block* current_block, AstNode* list_node) {
  /* Node = listStatement; Node -> Left = statement or NULL; Node -> Right = listStatement or NULL */
  AstNode* statement_node = list_node->left;
  if (!statement_node) return current_block;
  switch (statement_node->type) {
    case CFG_ACTION:
      current_block = _block_create_next_action(current_block, statement_node);
      break;
    case CFG_LOOP:
      current_block = _block_create_next_loop(current_block, statement_node);
      break;
    case CFG_CONDITION:
      current_block = _block_create_next_condition(current_block, statement_node);
      break;
    case CFG_SUBPROGRAMS:
      break;
    case CFG_SUBPROGRAM:
      break;
    case CFG_NONE:
      break;
  } 
  if (list_node->right) {
    current_block = _create_blocks_chain(current_block, list_node->right);
  }
  return current_block;
}

void _control_flow_create_subprograms_from_ast(ControlFlow* cf, AstNode* node, char* filename) {
  /* Check if source has another source */
  if (node->left) {
    _control_flow_create_subprograms_from_ast(cf, node->left, filename);
  }

  /* Check if source has sourceItem with function body */
  if (node->right && node->right->right) {
    Subprogram* subprogram = _create_subprogram(node->right, filename);
    control_flow_push(cf, subprogram);

    /* Pass Node = listStatement which is instructions inside function */
    Block* last_block = _create_blocks_chain(subprogram->start, node->right->right->left);
    _create_end_action_block(last_block);
  }
}

void control_flow_create_subprograms_from_ast(ControlFlow* cf, Ast* ast, char* filename) {
  _control_flow_create_subprograms_from_ast(cf, ast->head, filename);
}

char* _blocks_chain_to_dot(Block* current_block);

char* _action_block_to_dot(Block* block) {
  ActionBlockInfo* info = (ActionBlockInfo*)block->info;
  if (!info->next) {
    char* block_dot = malloc(
    sizeof(char) *
    (
      MAX_BLOCK_ID_LEN +
      strlen(block->value) +
      DOT_BLOCK_DEFINITION_SYNTAX_LEN +
      DOT_BLOCK_CONNECTION_SYNTAX_LEN +
      1
    )
  );
  sprintf(
    block_dot,
    "%d [label=\"%s\"];",
    block->id,
    block->value
  );
  return block_dot;
  }
  char* tail_blocks_dot = _blocks_chain_to_dot(info->next);
  char* block_dot = malloc(
    sizeof(char) *
    (
      MAX_BLOCK_ID_LEN * 3 +
      strlen(block->value) +
      strlen(tail_blocks_dot) +
      DOT_BLOCK_DEFINITION_SYNTAX_LEN +
      DOT_BLOCK_CONNECTION_SYNTAX_LEN +
      1
    )
  );
  sprintf(
    block_dot,
    "%d [label=\"%s\"];\n%d -> %d\n%s",
    block->id,
    block->value,
    block->id,
    info->next->id,
    tail_blocks_dot
  );
  return block_dot;
}

Block* _get_last_scope_block(Block* block) {
  switch (block->type) {
    case BLOCK_ACTION:
      ActionBlockInfo* action_info = (ActionBlockInfo*)block->info;
      if (!action_info->next) return block;
      return _get_last_scope_block(action_info->next);
    case BLOCK_LOOP:
      LoopBlockInfo* loop_info = (LoopBlockInfo*)block->info;
      if (!loop_info->next) return block;
      return _get_last_scope_block(loop_info->next);
    case BLOCK_CONDITION:
      ConditionBlockInfo* condition_info = (ConditionBlockInfo*)block->info;
      if (!condition_info->next) return block;
      return _get_last_scope_block(condition_info->next);
  }
  /* Unreachable */
  return NULL;
}

char* _loop_block_to_dot(Block* block) {
  LoopBlockInfo* info = (LoopBlockInfo*)block->info;
  char* inside_loop_blocks_dot = _blocks_chain_to_dot(info->body);
  Block* last_loop_block = _get_last_scope_block(info->body);
  char* after_loop_blocks_dot = "";
  if (info->next) after_loop_blocks_dot = _blocks_chain_to_dot(info->next);
  char* block_dot = malloc(
    sizeof(char) *
    (
      MAX_BLOCK_ID_LEN * 7 +
      strlen(block->value) +
      strlen(inside_loop_blocks_dot) +
      strlen(after_loop_blocks_dot) +
      DOT_CONTROL_DEFINITION_SYNTAX_LEN +
      DOT_BLOCK_CONNECTION_SYNTAX_LEN * 3 +
      2
    )
  );
  sprintf(
    block_dot,
    "%d [label=\"%s\",shape=diamond];\n%d -> %d\n%d -> %d\n%s\n%d -> %d\n%s",
    block->id,
    block->value,
    block->id,
    info->next->id,
    block->id,
    info->body->id,
    inside_loop_blocks_dot,
    last_loop_block->id,
    block->id,
    after_loop_blocks_dot 
  );
  free(inside_loop_blocks_dot);
  if (info->next) free(after_loop_blocks_dot);
  return block_dot;
}

char* _condition_block_to_dot(Block* block) {
  ConditionBlockInfo* info = (ConditionBlockInfo*)block->info;
  char* inside_if_blocks_dot = _blocks_chain_to_dot(info->if_body);
  Block* last_if_block = _get_last_scope_block(info->if_body);
  char* after_if_blocks_dot = "";
  if (info->next) after_if_blocks_dot = _blocks_chain_to_dot(info->next);
  if (info->else_body) {
    char* inside_else_blocks_dot = _blocks_chain_to_dot(info->else_body);
    Block* last_else_block = _get_last_scope_block(info->else_body);
    char* block_dot = malloc(
      sizeof(char) *
      (
        MAX_BLOCK_ID_LEN * 9 +
        strlen(block->value) +
        strlen(inside_if_blocks_dot) +
        strlen(inside_else_blocks_dot) +
        strlen(after_if_blocks_dot) +
        DOT_CONTROL_DEFINITION_SYNTAX_LEN +
        DOT_BLOCK_CONNECTION_SYNTAX_LEN * 4 +
        2
      )
    );
    sprintf(
      block_dot,
      "%d [label=\"%s\",shape=diamond];%d -> %d\n%d -> %d\n%s\n%d -> %d\n%s\n%d -> %d\n%s",
      block->id,
      block->value,
      block->id,
      info->if_body->id,
      block->id,
      info->else_body->id,
      inside_if_blocks_dot,
      last_if_block->id,
      info->next->id,
      inside_else_blocks_dot,
      last_else_block->id,
      info->next->id,
      after_if_blocks_dot
    );
    free(inside_if_blocks_dot);
    free(inside_else_blocks_dot);
    if (info->next) free(after_if_blocks_dot);
    return block_dot;
  }
  char* block_dot = malloc(
    sizeof(char) *
    (
      MAX_BLOCK_ID_LEN * 7 +
      strlen(block->value) +
      strlen(inside_if_blocks_dot) +
      strlen(after_if_blocks_dot) +
      DOT_CONTROL_DEFINITION_SYNTAX_LEN +
      DOT_BLOCK_CONNECTION_SYNTAX_LEN * 3 +
      1
    )
  );
  sprintf(
    block_dot,
    "%d [label=\"%s\",shape=diamond];\n%d -> %d\n%d -> %d\n%s\n%d -> %d\n%s",
    block->id,
    block->value,
    block->id,
    info->if_body->id,
    block->id,
    info->next->id,
    inside_if_blocks_dot,
    last_if_block->id,
    info->next->id,
    after_if_blocks_dot
  );
  free(inside_if_blocks_dot);
  if (info->next) free(after_if_blocks_dot);
  return block_dot;
}

char* _blocks_chain_to_dot(Block* current_block) {
  /* Block without value is end of subprogram */
  if (!current_block->value) {
    char* block_dot = malloc(sizeof(char) * (DOT_END_BLOCK_DEFINITION_SYNTAX_LEN + MAX_BLOCK_ID_LEN + 1));
    sprintf(block_dot, "%d [label=\"\",shape=circle];", current_block->id);
    return block_dot;
  }
  switch(current_block->type) {
    case BLOCK_ACTION:
      return _action_block_to_dot(current_block);
    case BLOCK_LOOP:
      return _loop_block_to_dot(current_block);
    case BLOCK_CONDITION:
      return _condition_block_to_dot(current_block);
  }
  /* Unreachable */
  return NULL;
}

char* subprogram_to_dot(Subprogram* subp) {
  ActionBlockInfo* start_block_info = (ActionBlockInfo*)subp->start->info;
  char* blocks_dot = _blocks_chain_to_dot(start_block_info->next);
  char* subprogram_dot = malloc(
    sizeof(char) * 
    (
      DOT_SUBPROGRAM_BASE_DEFINITION_LEN +
      strlen(subp->name) +
      MAX_BLOCK_ID_LEN * 3 +
      strlen(blocks_dot) +
      1
    )
  );
  sprintf(
    subprogram_dot,
    "digraph {"
    "node [shape=rectangle];"
    "subgraph cluster_0 {"
    "label=\"%s\";"
    "%d [label=\"\",shape=circle];\n%d->%d\n%s\n"
    "}}",
    subp->name,
    subp->start->id,
    subp->start->id,
    start_block_info->next->id,
    blocks_dot
  );
  free(blocks_dot);
  return subprogram_dot;
}

char* subprogram_get_dot_filename(Subprogram* subp) {
  char* name = malloc(sizeof(char) * (strlen(subp->filename) + strlen(subp->name) + 6));
  sprintf(name, "%s.%s.ext", subp->filename, subp->name);
  return name;
}


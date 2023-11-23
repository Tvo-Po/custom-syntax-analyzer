#include "ast.h"
#include "cfg.h"

#define CONTROL_FLOW_BUFF_STEP 10
#define SUBPROGRAM_CALLERS_BUFF_STEP 15

ControlFlow* create_control_flow() {
  cf = malloc(sizeof(ControlFlow));
  cf->size = CONTROL_FLOW_BUFF_STEP;
  cf->length = 0;
  cf->subprograms = malloc(CONTROL_FLOW_BUFF_STEP * sizeof(Subprogram*));
  return cf;
}

void control_flow_push(ControlFlow* cf, Subprogram* subprogram) {
  assert(cf->length <= cf->size);
  if (cf->length == cf->size) {
    cf->size += CONTROL_FLOW_BUFF_STEP;
    cf->subprograms = realloc(cf->subprograms, cf->size * sizeof(Subprogram*));
  }
  cf->subprograms[cf->size++] = subprogram;
}

unsign int _get_function_attrs_amount(AstNode* func_args_node) {
  static unsign int counter = 0;
  if (func_args_node->left) counter++;
  if (func_args_node->right) {
    counter++;
    _get_function_attrs_amount(func_args_node->right);
  }
  unsign int tmp_counter = counter;
  counter = 0;
  return tmp_counter;
}

Subprogram* _create_subprogram(Ast* subp_node, char* filename) {
  subp = malloc(sizeof(Subprogram));
  subp->start = NULL;
  subp->name = supb_node->left->value;
  subp->attrs_amount = _get_function_attrs_amount(Ast* supb_node->left->left);
  subp->filename = strdup(filename);
  subp->callers = malloc(sizeof(BlockList));
  subp->callers->size = SUBPROGRAM_CALLERS_BUFF_STEP;
  subp->callers->length = 0;
  subp->callers->blocks = malloc(SUBPROGRAM_CALLERS_BUFF_STEP * sizeof(Block*));
  return subp;
}

ErrorList* _subprogram_create_blocks_from_node(Subprogram* subp, AstNode* node) {
  
  
}

void _control_flow_get_all_subprograms(ControlFlow* cf, AstNode* node, char* filename) {
  if (node->left) {
      _control_flow_get_all_subprograms(cf, node->left);
  if (node->right && node->right->right) {
      control_flow_push(cf, _create_subprogram(node->right, filename));
      ErrorList* errors = _subprogram_create_blocks_from_node(
        cf.subprograms[cf->length - 1],
        node->right->right
      );
  }
}

void control_flow_create_subprograms_from_ast(ControlFlow* cf, Ast* ast, char* filename) {
  
}

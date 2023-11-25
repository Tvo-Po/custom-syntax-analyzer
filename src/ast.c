#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

#define MD_FULL_NODE_SYNTAX_LEN 18
#define MD_SHORT_NODE_SYNTAX_LEN 16
#define MD_NODE_CONNECTION_LEN 7
#define MD_FLOWCHART_GRAPH_WRAPPER_LEN 30

Ast* create_ast() {
  Ast* ast = malloc(sizeof(Ast));
  ast->counter = 1;
  ast->head = NULL;
  return ast;
}

void _destroy_node(AstNode* node) {
  if (!node) return;
  _destroy_node(node->left);
  _destroy_node(node->right);
  free(node->name);
  free(node->value);
  free(node);
}

void destroy_ast(Ast* ast) {
  if (!ast) return;
  _destroy_node(ast->head);
  free(ast);
}

AstNode* ast_create_node(Ast* ast, ControlStatementType type, char* name, char* value, AstNode* left, AstNode* right) {
  AstNode* node = malloc(sizeof(AstNode));
  node->id = ast->counter++;
  node->type = type;
  assert(name);
  node->name = strdup(name);
  strcpy(node->name, name);
  if (value) {
    node->value = strdup(value);
    strcpy(node->value, value);
  }
  else {
    node->value = NULL;
  }
  node->left = left;
  node->right = right;
  return node;
}

char* _create_node_string(AstNode* node) {
  char* node_string = NULL;
  if (!node->value || node->value[0] == '\0') {
    node_string = malloc(strlen(node->name) + MD_SHORT_NODE_SYNTAX_LEN);
    sprintf(node_string, "node%d([\"%s\"])", node->id, node->name);
    return node_string;
  }
  node_string = malloc(strlen(node->name) + strlen(node->value) + MD_FULL_NODE_SYNTAX_LEN);
  sprintf(node_string, "node%d([\"%s: %s\"])", node->id, node->name, node->value);
  return node_string;
}

char* _node_to_md(AstNode* node, char* parent_node_string) {
  if (!node->left && !node->right) {
    char* leaf_node_string = malloc(
      strlen(parent_node_string) +
      MD_NODE_CONNECTION_LEN +
      strlen(node->name) +
      strlen(node->value) +
      MD_FULL_NODE_SYNTAX_LEN
    );
    sprintf(
      leaf_node_string,
      "%s --> node%d([\"%s: %s\"])\n",
      parent_node_string, node->id,
      node->name,
      node->value
    );
    return leaf_node_string;
  }

  char* node_string = NULL; char* left_strings = NULL; char* right_strings = NULL;
  node_string = _create_node_string(node);
  long unsigned int md_buff_size = 0;
  if (node->left) {
    left_strings = _node_to_md(node->left, node_string);
    md_buff_size += strlen(left_strings);
  }
  if (node->right) {
    right_strings = _node_to_md(node->right, node_string);
    md_buff_size += strlen(right_strings);
  }

  if (parent_node_string[0] == '\0') {
    char* md = malloc(md_buff_size + MD_FLOWCHART_GRAPH_WRAPPER_LEN);
     sprintf(
      md,
      "```mermaid\nflowchart TB\n%s\n%s```",
      left_strings ? left_strings : "",
      right_strings ? right_strings : ""
    );
    free(left_strings);
    free(right_strings);
    free(node_string);
    return md;
  }

  char* md = malloc(
    strlen(parent_node_string) +
    strlen(node_string) +
    MD_NODE_CONNECTION_LEN +
    md_buff_size
  );
  sprintf(
    md,
    "%s --> %s\n%s%s",
    parent_node_string,
    node_string,
    left_strings ? left_strings : "",
    right_strings ? right_strings : ""
  );
  free(left_strings);
  free(right_strings);
  free(node_string);
  return md;
}

char* ast_to_md(Ast* ast) {
  if (!ast->head) {
    return NULL;
  }
  return _node_to_md(ast->head, "");
}

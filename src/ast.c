#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

#define NODE_STRING_LENGTH 40

/* Pick size for both nodes strings +6 chars on arrow and new line */
#define MD_LINE_SIZE NODE_STRING_LENGTH * 2 + 6

Ast* create_ast() {
  Ast* ast = malloc(sizeof(Ast));
  ast->counter = 1;
  return ast;
}

void _destroy_node(AstNode* node) {
  if (node->left) {
    _destroy_node(node->left);
  }
  if (node->right) {
    _destroy_node(node->right);
  }
  free(node->name);
  free(node->value);
  free(node);
}

void destroy_ast(Ast* ast) {
  if (ast->head) {
    _destroy_node(ast->head);
  }
  free(ast);
}

AstNode* ast_create_node(Ast* ast, char* name, char* value, AstNode* left, AstNode* right) {
  AstNode* node = malloc(sizeof(AstNode));
  node->id = ast->counter++;
  if (node->name) {
    node->name = strcpy(malloc(sizeof(char)), name);
  }
  else {
    node->name = NULL;
  }
  if (node->value) {
    node->value = strcpy(malloc(sizeof(char)), value);
  }
  else {
    node->value = NULL;
  }
  node->left = left;
  node->right = right;
  return node;
}

char* _create_node_string(AstNode* node) {
  char* node_string = malloc(NODE_STRING_LENGTH * sizeof(char));
  if (node->left->value[0]) {
    sprintf(node_string, "node%d([%s: %s])", node->id, node->name, node->value);
  }
  else {
    sprintf(node_string, "node%d([%s])", node->id, node->name ? node->name :"unnamed element");
  }
  return node_string;
}

char* _node_to_md(AstNode* node, char* parent_node_string) {
  if (!node->left && !node->right) {
    char* leaf_node_string = malloc(sizeof(char) * MD_LINE_SIZE);
    sprintf(leaf_node_string, "%s --> node%d([%s: %s])", parent_node_string, node->id, node->name, node->value);
    return leaf_node_string;
  }
  char *node_string, *left_strings, *right_strings;
  node_string = _create_node_string(node);
  int md_buff_size = sizeof(char) * MD_LINE_SIZE;
  if (node->left) {
    left_strings = _node_to_md(node->left, node_string);
    md_buff_size += sizeof(left_strings);
  }
  if (node->right) {
    right_strings = _node_to_md(node->right, node_string);
    md_buff_size += sizeof(right_strings);
  }
  char* md = malloc(sizeof(md_buff_size));
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
  puts("There we are");
  if (!ast->head) {
    return NULL;
  }
  return _node_to_md(ast->head, "");
}

#include <stdlib.h>
#include <string.h>
#include "ast.h"

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
  _destroy_node(ast->head);
  free(ast);
}

AstNode* ast_create_node(Ast* ast, char* name, char* value, AstNode* left, AstNode* right) {
  AstNode* node = malloc(sizeof(AstNode));
  node->id = ast->counter++;
  node->name = strcpy(malloc(sizeof(char)), name);
  node->value = strcpy(malloc(sizeof(char)), value);
  node->left = left;
  node->right = right;
  return node;
}

char* ast_to_gml(Ast* ast) {
  return "";
}

#include <stdio.h>
#include "ast.h"

void yyerror(Ast* ast, const char* s) {
  fprintf(stderr, "%s\n", s);
}

int main() {
  printf("Start\n");
}

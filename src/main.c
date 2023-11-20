#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

#define INPUT_FILE "input.undef"
#define OUTPUT_FILE "output.md"

extern FILE* yyin;

void yyerror(Ast* ast, const char* s) {
  fprintf(stderr, "%s\n", s);
}

int main() {
  FILE* input = fopen(INPUT_FILE, "r");

  if (!input) {
    printf("Can not open file: %s", INPUT_FILE);
    return 1;
  }

  Ast* ast = create_ast();
  yyin = input;
  int result = yyparse(ast);
  fclose(input);
  if (result != 0) goto fail;

  FILE* output = fopen(OUTPUT_FILE, "w");
  if (!output) {
    printf("Can not open file: %s", OUTPUT_FILE);
    goto fail;
  }

  char* md = ast_to_md(ast);
  fputs(md ? md : "", output);
  fclose(output);
  free(md);
  destroy_ast(ast);
  return 0;

  fail:   
    destroy_ast(ast);
    return 1;
}

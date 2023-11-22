#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

#define OUTPUT_FILE "output.md"

extern FILE* yyin;
extern int yy_flex_debug;

void yyerror(Ast* ast, const char* s) {
  fprintf(stderr, "[!] %s\n", s);
}

int main(int argc, char* argv[]) {
  puts("[+] Start parsing...");

  if (argc != 2) {
    printf("[!] Invalid usage: %s filename \n", argv[0]);
  }

  yy_flex_debug = 1;
  FILE* input = fopen(argv[1], "r");

  if (!input) {
    printf("[!] Can not open file: %s\n", argv[1]);
    return 1;
  }

  Ast* ast = create_ast();
  yyin = input;
  int result = yyparse(ast);
  fclose(input);
  if (result != 0) goto fail; 

  FILE* output = fopen(OUTPUT_FILE, "w");
  if (!output) {
    printf("[!] Can not open file: %s\n", OUTPUT_FILE);
    goto fail;
  }

  char* md = ast_to_md(ast);
  fputs(md ? md : "", output);
  fclose(output);
  free(md);
  destroy_ast(ast);
  printf("[+] Code successfully parsed to: %s\n", OUTPUT_FILE);
  return 0;

  fail:   
    destroy_ast(ast);
    return 1;
}

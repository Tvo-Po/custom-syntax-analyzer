#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
#include "cfg.h"

#define MALLOC_CHECK_ 2

extern FILE* yyin;
extern int yyparse(Ast* ast);

void yyerror(Ast* ast, const char* s) {
  fprintf(stderr, "[!] %s\n", s);
}

int main(int argc, char* argv[]) {
  puts("[+] Start parsing...");
  
  ControlFlow* control_flow = create_control_flow();
  Ast* ast = NULL;

  if (argc < 2) {
    printf("[!] Invalid usage: %s [filename...] \n", argv[0]);
    return 1;
  }
  
  for (int i = 1; i < argc; i++) {
    FILE* input = fopen(argv[i], "r");

    if (!input) {
      printf("[!] Can not open file: %s\n", argv[1]);
      goto fail;
    }

    ast = create_ast();
    yyin = input;
    int result = yyparse(ast);
    fclose(input);
    if (result != 0) goto fail;

    control_flow_create_subprograms_from_ast(control_flow, ast, argv[i]);
    destroy_ast(ast);
  }
  
  for (int i = 0; i < control_flow->length; i++) {
    Subprogram* subp = control_flow->subprograms[i];
    char* subprogram_dot = subprogram_to_dot(subp);
    char* subprogram_dot_filename = subprogram_get_dot_filename(subp);
    FILE* output = fopen(subprogram_dot_filename, "w");


    if (!output) {
      printf("[!] Can not open file: %s\n", subprogram_dot_filename);
      goto fail;
    }
    
    fputs(subprogram_dot, output);
    fclose(output);
    free(subprogram_dot);
    free(subprogram_dot_filename);
  }

  destroy_control_flow(control_flow);
  puts("[+] Parsing done...");
  return 0;

fail: 
  destroy_control_flow(control_flow);
  destroy_ast(ast);
  return 1;
}

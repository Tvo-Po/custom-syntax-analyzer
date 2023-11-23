#include "ast.h"

struct ControlFlow {
  unsigned int size;
  unsigned int length;
  Subprogram** subprograms;
  ControlFlowErrors* errors;
};

struct ControlFlowErrors {
  unsigned int size;
  unsigned int length;
  char** messages;
}

ControlFlow* create_control_flow();

ControlFlow* control_flow_push(ControlFlow* cf, Subprogram* Subprogram);

void control_flow_create_subprograms_from_ast(ControlFlow* cf, Ast* ast, char* filename);

void control_flow_resolve_callers(ControlFlow cf);

struct Subprogram {
  Block* start;
  char* name;
  unsigned short attrs_amount;
  char* filename;
  BlockList* callers;
}

char* subprogram_to_dot(Subprogram* subp);

struct BlockList {
  unsigned int size;
  unsigned int length;
  Block** blocks;
}

struct Block {
  unsigned int id;
  ControlStatementType type,
  Block* prev;
  Block* inner;
  Block* next;
  char* value,
};

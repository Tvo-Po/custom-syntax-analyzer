typedef struct ControlFlow ControlFlow;
typedef struct Subprogram Subprogram;
typedef enum BlockInfoType BlockInfoType;
typedef struct ActionBlockInfo ActionBlockInfo;
typedef struct LoopBlockInfo LoopBlockInfo;
typedef struct ConditionBlockInfo ConditionBlockInfo;
typedef struct Block Block;

struct ControlFlow {
  unsigned int size;
  unsigned int length;
  Subprogram** subprograms;
};

ControlFlow* create_control_flow();

void destroy_control_flow(ControlFlow* cf);

void control_flow_push(ControlFlow* cf, Subprogram* Subprogram);

void control_flow_create_subprograms_from_ast(ControlFlow* cf, Ast* ast, char* filename);

struct Subprogram {
  Block* start;
  char* name;
  char* filename;
};

char* subprogram_to_dot(Subprogram* subp);

char* subprogram_get_dot_filename(Subprogram* subp);

enum BlockInfoType {
  BLOCK_ACTION,
  BLOCK_LOOP,
  BLOCK_CONDITION,
};

struct ActionBlockInfo {
  Block* prev;
  Block* next;
};

struct LoopBlockInfo {
  Block* prev;
  Block* body;
  Block* next;
};

struct ConditionBlockInfo {
  Block* prev;
  Block* if_body;
  Block* else_body;
  Block* next;
};

struct Block {
  unsigned int id;
  BlockInfoType type;
  char* value;
  void* info;
};

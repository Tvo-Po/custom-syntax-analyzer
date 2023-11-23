typedef struct Ast Ast;
typedef enum ControlStatementType ControlStatementType;
typedef struct AstNode AstNode;

struct Ast {
  unsigned short int counter;
  AstNode* head;
};

Ast* create_ast();

void destroy_ast(Ast* ast);

AstNode* ast_create_node(Ast* ast, ControlStatementType type, char* name, char* value, AstNode* left, AstNode* right);

char* ast_to_md(Ast* ast);

enum ControlStatementType {
  CFG_NONE,
  CFG_ACTION,
  CFG_CONDITION,
  CFG_LOOP,
  CFG_SUBPROGRAM,
  CFG_SUBPROGRAMS
};

struct AstNode {
  int id;
  ControlStatementType type;
  char* name;
  char* value;
  AstNode* left;
  AstNode* right;
};

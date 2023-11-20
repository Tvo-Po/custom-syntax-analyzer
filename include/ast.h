typedef struct Ast Ast;
typedef struct AstNode AstNode;

struct Ast {
  int counter;
  AstNode* head;
};

void destroy_ast(Ast* ast);

AstNode* create_ast_node(Ast* ast, char* name, char* value, AstNode* left, AstNode* right);

struct AstNode {
  int id;
  char* name;
  char* value;
  AstNode* left;
  AstNode* right;
};

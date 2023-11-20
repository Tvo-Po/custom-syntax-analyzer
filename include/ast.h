typedef struct Ast Ast;
typedef struct AstNode AstNode;

struct Ast {
  int counter;
  AstNode* head;
};

Ast* create_ast();

void destroy_ast(Ast* ast);

AstNode* ast_create_node(Ast* ast, char* name, char* value, AstNode* left, AstNode* right);

char* ast_to_gml(Ast* ast);

struct AstNode {
  int id;
  char* name;
  char* value;
  AstNode* left;
  AstNode* right;
};

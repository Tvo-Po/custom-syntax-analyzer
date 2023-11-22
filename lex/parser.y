%{
  #include <stddef.h>
  #define YYDEBUG 1
%}

%error-verbose

%code requires {
  #include "ast.h"
  
  extern void yyerror(Ast* ast, const char* s);
}

%union {
  AstNode* node;
}

%parse-param {Ast* ast}
%lex-param {Ast* ast}

%token <node> PLUS MINUS STAR SLASH PERCENT EQUAL NOTEQUAL
%token <node> LESSTHAN GREATERTHAN LESSTHANEQ GREATERTHANEQ
%token <node> AND OR NOT
%token <node> IDENTIFIER
%token <node> STR
%token <node> COMMA
%token <node> CHAR
%token <node> BIN HEX DEC
%token <node> TRUE FALSE
%token <node> IF THEN ELSE LOOP WHILE UNTIL DO BREAK END WEND
%token <node> SEMICOLON
%token <node> LPAREN RPAREN
%token <node> TYPEDEF
%token <node> DIM
%token <node> AS
%token <node> FUNCTION
%token <node> ARRAY_COMMAS

%type <node> expr
%type <node> typeRef
%type <node> funcSignature
%type <node> optionalFuncBody
%type <node> argDef
%type <node> sourceItem
%type <node> statement
%type <node> var
%type <node> listIdentifier
%type <node> if
%type <node> while
%type <node> do
%type <node> break
%type <node> expression
%type <node> builtin
%type <node> custom
%type <node> array
%type <node> source
%type <node> listArgDef
%type <node> optionalTypeRef
%type <node> literal
%type <node> place
%type <node> listExpr
%type <node> callOrIndexer
%type <node> braces
%type <node> unary
%type <node> binary
%type <node> optionalElseStatement
%type <node> listStatement


%%
/* SourceItem */
source: %empty {{$$ = NULL;}}
    | source sourceItem {{
        ast->head = ast_create_node(ast, "Source", "", $1, $2);
        $$ = ast->head;
    }};

sourceItem: FUNCTION funcSignature optionalFuncBody {{$$ = ast_create_node(ast, "Source Item", "", $2, $3);}};

optionalFuncBody: %empty {{$$ = NULL;}}
    | listStatement END FUNCTION {{$$ = ast_create_node(ast, "Function Body", "", $1, NULL);}};


/* FuncSignature */
funcSignature: IDENTIFIER LPAREN listArgDef RPAREN optionalTypeRef {{
    $$ = ast_create_node(ast, "Function Signature", $1->value, $3, $5);
}};

listArgDef: %empty {{$$ = NULL;}}
    | argDef {{$$ = $1;}}
    | argDef COMMA listArgDef {{$$ = ast_create_node(ast, "Function Arguments", "", $1, $3);}};

argDef: IDENTIFIER optionalTypeRef {{$$ = ast_create_node(ast, "Argument Definition", "", $1, $2);}};

optionalTypeRef: %empty {{$$ = NULL;}}
    | AS typeRef {{$$ = $2;}};


/* TypeRef */
typeRef: builtin {{$$ = $1;}}
    | custom {{$$ = $1;}}
    | array {{$$ = $1;}};

builtin: TYPEDEF {{$$ = $1;}};

custom: IDENTIFIER {{$$ = $1;}};

array: typeRef ARRAY_COMMAS {{$$ = ast_create_node(ast, "Array", $2->value, $1, NULL);}};


/* Statement */
statement: var {{$$ =  $1;}}
    | if {{$$ =  $1;}}
    | while {{$$ =  $1;}}
    | do {{$$ =  $1;}}
    | break {{$$ =  $1;}}
    | expression {{$$ =  $1;}};

listStatement: %empty {{$$ = NULL;}}
    | statement listStatement {{$$ = ast_create_node(ast, "Statements", "", $1, $2);}};

var: DIM listIdentifier AS typeRef {{$$ = ast_create_node(ast, "Variables Declaration", "", $2, $4);}}

listIdentifier: %empty {{$$ = NULL;}}
    | IDENTIFIER {{$$ = $1;}}
    | IDENTIFIER COMMA listIdentifier {{$$ = ast_create_node(ast, "Identifiers", "", $1, $3);}};

if: IF expr THEN listStatement optionalElseStatement END IF {{
    $$ = ast_create_node(ast, "if", "", $2, ast_create_node(ast, "If Body", "", $4, $5));
  }};

optionalElseStatement: %empty {{$$ = NULL;}}
    | ELSE listStatement {{$$ = ast_create_node(ast, "Else Body", "", $2, NULL);}};

while: WHILE expr listStatement WEND {{$$ = ast_create_node(ast, "While", "", $2, $3);}};

do: DO listStatement LOOP WHILE expr {{$$ = ast_create_node(ast, "Do While", "", $2, $5);}}
  | DO listStatement LOOP UNTIL expr {{$$ = ast_create_node(ast, "Do Until", "", $2, $5);}};

break: BREAK {{$$ = $1;}};

expression: expr SEMICOLON {{$$ = $1;}};


/* Expr */
expr: unary          {{$$ = $1;}}
    | binary         {{$$ = $1;}}
    | braces         {{$$ = $1;}}
    | callOrIndexer  {{$$ = $1;}}
    | place          {{$$ = $1;}}
    | literal        {{$$ = $1;}};

binary: expr EQUAL expr {{$$ = ast_create_node(ast, "ASSIGNMENT", "", $1, $3);}}
    | expr PLUS expr {{$$ = ast_create_node(ast, "PLUS", "", $1, $3);}}
    | expr MINUS expr {{$$ = ast_create_node(ast, "MINUS", "", $1, $3);}}
    | expr STAR expr {{$$ = ast_create_node(ast, "STAR", "", $1, $3);}}
    | expr SLASH expr {{$$ = ast_create_node(ast, "SLASH", "", $1, $3);}}
    | expr PERCENT expr {{$$ = ast_create_node(ast, "PERCENT", "", $1, $3);}}
    | expr EQUAL EQUAL expr {{$$ = ast_create_node(ast, "EQUALITY", "", $1, $4);}}
    | expr NOTEQUAL expr {{$$ = ast_create_node(ast, "NOTEQUAL", "", $1, $3);}}
    | expr LESSTHAN expr {{$$ = ast_create_node(ast, "LESSTHAN", "", $1, $3);}}
    | expr GREATERTHAN expr {{$$ = ast_create_node(ast, "GREATERTHAN", "", $1, $3);}}
    | expr LESSTHANEQ expr {{$$ = ast_create_node(ast, "LESSTHANEQ", "", $1, $3);}}
    | expr GREATERTHANEQ expr {{$$ = ast_create_node(ast, "GREATERTHANEQ", "", $1, $3);}}
    | expr AND expr {{$$ = ast_create_node(ast, "AND", "", $1, $3);}}
    | expr OR expr {{$$ = ast_create_node(ast, "OR", "", $1, $3);}};

unary: PLUS expr {{$$ = ast_create_node(ast, "PLUS", "", $2, NULL);}}
    | MINUS expr {{$$ = ast_create_node(ast, "MINUS", "", $2, NULL);}}
    | NOT expr {{$$ = ast_create_node(ast, "NOT", "", $2, NULL);}};

braces: LPAREN expr RPAREN  {{$$ = ast_create_node(ast, "BRACES", "", $2, NULL);}};

callOrIndexer: expr LPAREN listExpr RPAREN  {{$$ = ast_create_node(ast, "CALLORINDEXER", "", $1, $3);}};

listExpr: expr COMMA listExpr {{$$ = ast_create_node(ast, "Expressions", "", $1, $3);}}
    | expr {{$$ = $1;}}
    | %empty {{$$ = NULL;}};

place: IDENTIFIER {{$$ = $1;}};

literal: TRUE {{$$ = $1;}}
    | FALSE {{$$ = $1;}}
    | STR {{$$ = $1;}}
    | CHAR {{$$ = $1;}}
    | HEX {{$$ = $1;}}
    | BIN {{$$ = $1;}}
    | DEC {{$$ = $1;}};
%%

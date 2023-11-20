%{
#include <string.h>
#include "parser.tab.h"
#define YY_DECL int yylex(YYSTYPE* yylval_param, Ast* ast)
%}


%%

[0-9]+ {
    yylval.node = ast_create_node(ast, "DEC", yytext, NULL, NULL);
    return DEC;
}
\"[^\"\\]*(?:\\.[^\"\\]*)*\" {
    char buffer[1024];
    strncpy(buffer, yytext+1, strlen(yytext)-2);
    buffer[strlen(buffer)-1] = 0;
    yylval.node = ast_create_node(ast, "STR", buffer, NULL, NULL);
    return STR;
}
'[^']' {
    char buffer[1];
    strncpy(buffer, yytext+1, 1);
    yylval.node = ast_create_node(ast, "CHAR", buffer, NULL, NULL);
    return CHAR;
}
\(,*\) {
    yylval.node = ast_create_node(ast, "ARRAY_COMMAS", yytext, NULL, NULL);
    return ARRAY_COMMAS;
}

0[xX][0-9A-Fa-f]+ {
    char* buffer = malloc(256);
    sprintf(buffer, "%d", strtol(yytext + 2, NULL, 16));
    yylval.node = ast_create_node(ast, "HEX", buffer, NULL, NULL);
    return HEX;
}
0[bB][01]+ {
    char* buffer = malloc(256);
    sprintf(buffer, "%d", strtol(yytext + 2, NULL, 2));
    yylval.node = ast_create_node(ast, "BIN", buffer, NULL, NULL);
    return BIN;
}
"byte" {
           yylval.node = ast_create_node(ast, "TYPEDEF", yytext, NULL, NULL);
           return TYPEDEF;
       }
"int" {
          yylval.node = ast_create_node(ast, "TYPEDEF", yytext, NULL, NULL);
          return TYPEDEF;
      }
"uint" {
           yylval.node = ast_create_node(ast, "TYPEDEF", yytext, NULL, NULL);
           return TYPEDEF;
       }
"long" {
           yylval.node = ast_create_node(ast, "TYPEDEF", yytext, NULL, NULL);
           return TYPEDEF;
       }
"bool" {
           yylval.node = ast_create_node(ast, "TYPEDEF", yytext, NULL, NULL);
           return TYPEDEF;
       }
"ulong" {
            yylval.node = ast_create_node(ast, "TYPEDEF", yytext, NULL, NULL);
            return TYPEDEF;
        }
"char" {
           yylval.node = ast_create_node(ast, "TYPEDEF", yytext, NULL, NULL);
           return TYPEDEF;
       }
"string"  {
              yylval.node = ast_create_node(ast, "TYPEDEF", yytext, NULL, NULL);
              return TYPEDEF;
          }
"if"                                {
 yylval.node = ast_create_node(ast, "IF", "", NULL, NULL);
 return IF;
 }
"then"                                {
 yylval.node = ast_create_node(ast, "THEN", "", NULL, NULL);
 return THEN;
 }
"else"                              {
 yylval.node = ast_create_node(ast, "ELSE", "", NULL, NULL);
 return ELSE;
 }
"do"                                {
 yylval.node = ast_create_node(ast, "DO", "", NULL, NULL);
 return DO;
 }
"loop"                             {
 yylval.node = ast_create_node(ast, "LOOP", "", NULL, NULL);
 return LOOP;
 }
"while"                             {
 yylval.node = ast_create_node(ast, "WHILE", "", NULL, NULL);
 return WHILE;
 }
"until"                             {
 yylval.node = ast_create_node(ast, "UNTIL", "", NULL, NULL);
 return UNTIL;
 }
"break"                             {
 yylval.node = ast_create_node(ast, "BREAK", "", NULL, NULL);
 return BREAK;
 }
"end"                             {
 yylval.node = ast_create_node(ast, "END", "", NULL, NULL);
 return END;
 }
"wend"                             {
 yylval.node = ast_create_node(ast, "WEND", "", NULL, NULL);
 return WEND;
 }
"true"                              {
 yylval.node = ast_create_node(ast, "TRUE", "", NULL, NULL);
 return TRUE;
 }
"false"                             {
 yylval.node = ast_create_node(ast, "FALSE", "", NULL, NULL);
 return FALSE;
 }
"%"                                 {
 return PERCENT;
 }
";"                                 {
 return SEMICOLON;
 }
","                                 {
 return COMMA;
 }
"!="                                {
 return NOTEQUAL;
 }
"!"                                 {
 return NOT;
 }
"\|\|"                              {
 return OR;
 }
"&&"                                {
 return AND;
 }
"+"                                 {
 return PLUS;
 }
"-"                                 {
 return MINUS;
 }
"<="                                {
 return LESSTHANEQ;
 }
">="                                {
 return GREATERTHANEQ;
 }
"<"                                 {
 return LESSTHAN;
 }
">"                                 {
 return GREATERTHAN;
 }
"*"                                 {
 return STAR;
 }
"("                                 {
 return LPAREN;
 }
")"                                 {
 return RPAREN;
 }
"="                                 {
 return EQUAL;
 }
"dim"                                 {
 yylval.node = ast_create_node(ast, "DIM", yytext, NULL, NULL);
 return DIM;
 }
"as"                                 {
 yylval.node = ast_create_node(ast, "AS", yytext, NULL, NULL);
 return AS;
 }
"function"                                 {
 yylval.node = ast_create_node(ast, "FUNCTION", yytext, NULL, NULL);
 return FUNCTION;
 }
[a-zA-Z_][a-zA-Z_0-9]* {
    yylval.node = ast_create_node(ast, "IDENTIFIER", yytext, NULL, NULL);
    return IDENTIFIER;
}
\/\/.*                               { /* Пропустить комментарии */ }
\n                                  { /* Пропустить переводы строк */ }
[ \t]                               { /* Пропустить пробелы и табуляцию */ }
.                                   {
                                        // Обработка нераспознанных символов или ошибок
                                        fprintf(stderr, "Нераспознанный символ: %s\n", yytext);
                                    }
%%


int yywrap() {
    // Your implementation here, typically returning 1 to signal EOF.
    return 1;
}

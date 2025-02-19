#include <string.h>
#include "token.h"
#include "../utils/utils.h"


struct Token newToken(enum token_type type, char* literal) {
  struct Token t = {type, literal};
  return t;
}

struct Token createStringWildcardToken() {
  struct Token t = {IDENT, "*"};
  return t;
}

struct Token getTokenFromLitteral(char* w) {
  if (isNumber(w)) 
    return newToken(INT_TOK, "INT_TOK");

  if (strlen(w) == 1) {
      switch (w[0]) {
        case '=':
          return newToken(ASSIGN, "ASSIGN");     
        case '<':
          return newToken(LT, "LT");     
        case '>':
          return newToken(GT, "GT");     
        case ';':
          return newToken(SEMICOLON, "SEMICOLON");     
        case '(':
          return newToken(LPAREN, "LPAREN");     
        case ')':
          return newToken(RPAREN,"RPAREN");     
        case ',':
          return newToken(COMMA,"COMMA");     
        case '!':
          return newToken(BANG,"BANG");     
        case '+':
          return newToken(PLUS,"PLUS");     
        case '-':
          return newToken(MINUS,"MINUS");     
        case '/':
          return newToken(DIV,"DIV");     
        case '*':
          return newToken(MULT,"MULT");     
        case '{':
          return newToken(LBRACE,"LBRACE");     
        case '}':
          return newToken(RBRACE,"RBRACE");     
        case 0:
          return newToken(EOF_TOK,"EOF_TOK");     
        default:
          return newToken(ILLEGAL,"ILLEGAL");
    }
  }
  else {
    if (strcmp(w, "let") == 0)
      return newToken(LET, "LET");

    else if (strcmp(w, "function") == 0)
      return newToken(FUNCTION, "FUNCTION");

    else if (strcmp(w, "if") == 0)
      return newToken(IF, "IF");

    else if (strcmp(w, "==") == 0)
      return newToken(EQ, "EQ");

    else if (strcmp(w, "!=") == 0)
      return newToken(NOT_EQ, "NOT_EQ");

    else if (strcmp(w, "else") == 0)
      return newToken(ELSE, "ELSE");

    else if (strcmp(w, "return") == 0)
      return newToken(RETURN, "RETURN");

    else if (strcmp(w, "true") == 0)
      return newToken(TRUE, "TRUE");
      
    else if (strcmp(w, "false") == 0)
      return newToken(FALSE, "FALSE");

    else if (strcmp(w, "for") == 0)
      return newToken(FALSE, "FOR");

    else if (strcmp(w, "in") == 0)
      return newToken(FALSE, "IN");

    else if (strcmp(w, "range") == 0)
      return newToken(FALSE, "RANGE");
    else 
      return newToken(IDENT, "IDENT");
  }
}



#include <string.h>
#include "token.h"
#include "../utils/utils.h"


struct Token newToken(enum token_type type, char* literal) {
  struct Token t = {type, literal};
  return t;
}

struct Token getTokenFromLitteral(char* w) {
  if (isNumber(w)) 
    return newToken(INT_TOK, w);

  if (strlen(w) == 1) {
      switch (w[0]) {
        case '=':
          return newToken(ASSIGN, w);     
        case ';':
          return newToken(SEMICOLON, w);     
        case '(':
          return newToken(LPAREN, w);     
        case ')':
          return newToken(RPAREN, w);     
        case ',':
          return newToken(COMMA, w);     
        case '+':
          return newToken(PLUS, w);     
        case '{':
          return newToken(LBRACE, w);     
        case '}':
          return newToken(RBRACE, w);     
        case 0:
          return newToken(EOF_TOK, w);     
        default:
          return newToken(ILLEGAL, w);
    }
  }
  else {
    if (strcmp(w, "let") == 0)
      return newToken(LET, w);

    else if (strcmp(w, "function") == 0)
      return newToken(FUNCTION, w);

    else 
      return newToken(IDENT, w);
  }
}



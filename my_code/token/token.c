#include "token.h"
#include "../lexer/lexer.h"

struct Token newToken(enum token_type type, char* literal) {
  struct Token t = {type, literal};
  return t;
}

struct Token getCurrentToken(struct Lexer* l) {
  char* current_word;

  readNextWord(l, current_word); 
  struct Token tok;
  if (isChar(current_word)) {
    int i = 0;
  }
  else {

    switch (l->ch) {
      case '=':
        tok = newToken(ASSIGN, &l->ch);     
        break;
      case ';':
        tok = newToken(SEMICOLON, &l->ch);     
      case '(':
        tok = newToken(LPAREN, &l->ch);     
        break;
      case ')':
        tok = newToken(RPAREN, &l->ch);     
        break;
      case ',':
        tok = newToken(COMMA, &l->ch);     
        break;
      case '+':
        tok = newToken(PLUS, &l->ch);     
        break;
      case '{':
        tok = newToken(LBRACE, &l->ch);     
        break;
      case '}':
        tok = newToken(RBRACE, &l->ch);     
        break;
      case 0:
        tok = newToken(EOF_TOK, &l->ch);     
        break;
    }
  }
  return tok;
}


struct Token NextToken(struct Lexer* l) { 
  moveCursorLexer(l);
  return getCurrentToken(l);
}


char* token_type_to_string[] = {
    "ILLEGAL", "EOF",
    "IDENT", "INT",
    "ASSIGN", "PLUS",
    "COMMA",
    "SEMICOLON",
    "LPAREN", "RPAREN", "LBRACE", "RBRACE",
    "FUNCTION",
    "LET"
};


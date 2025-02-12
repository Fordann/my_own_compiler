#include <stdlib.h>
#include "lexer.h"


struct Lexer* newLexer(char* input) {
  struct Lexer* l = malloc(sizeof(struct Lexer)); 
  l->input = input;
  return l;
}


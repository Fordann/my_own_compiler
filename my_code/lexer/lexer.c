#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "lexer.h"


//ne supporte que les caractères ASCII
char readCurrentChar(struct Lexer* l) {
  if (l->readPosition > l->input_length ) { 
    return 0;
  }
  else {
    return l->input[l->readPosition];
  }
}

void moveCursorLexer(struct Lexer* l) {
  l->position = l->readPosition;
  l->readPosition++;
}

char lookAHead(struct Lexer* l, int steps) {
  //assert (((l->readPosition + steps < 0) || (l->readPosition + steps > l->input_length))) && "lookAHead is trying to look out of the boundaries of the program";
  return l->input[l->readPosition + steps];
  }

void readNextChar(struct Lexer* l) {
  moveCursorLexer(l);
  l->ch = readCurrentChar(l);
}

struct Lexer* newLexer(char* input) {
  struct Lexer* l = malloc(sizeof(struct Lexer)); 
  l->input = input;
  l->input_length = strlen(input);
  l->position = 0;
  l->readPosition = 0;
  l->ch = readCurrentChar(l);
  return l;
}


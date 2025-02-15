#include <string.h>
#include <assert.h>

#include "lexer.h"
#include "../utils/utils.h"


//ne supporte que les caractères ASCII
char readCurrentChar(const struct Lexer* l) {
  if (l->readPosition >= l->input_length ) { 
    return 0;
  }
  else {
    return l->input[l->readPosition];
  }
}


void readCurrentWord(struct Lexer* l, char* result_word) {
  int word_length = 0;
  
  if (isSpecialChar(l->ch)) {
    result_word[0] = l->ch;
    word_length++;
  }

  while (!isSpecialChar(l->ch) && l->ch != ' ') {
    result_word[word_length] = l->ch;
    readNextChar(l);
    word_length++;
  }
  result_word[word_length] = 0;
}

void moveCursorUntilChar(struct Lexer* l) {
  while ((l->position <= l->input_length) && (!isChar(l->ch) && (l->ch != ' '))) {
    readNextChar(l);
  }
}

void readNextWord(struct Lexer* l, char* result_word) {
  moveCursorUntilChar(l);
  readCurrentWord(l, result_word);
}


void moveCursorLexer(struct Lexer* l) {
  l->position = l->readPosition;
  l->readPosition++;
}

char lookAHead(const struct Lexer* l, int steps) {
  //assert (((l->readPosition + steps < 0) || (l->readPosition + steps > l->input_length))) && "lookAHead is trying to look out of the boundaries of the program";
  return l->input[l->readPosition + steps];
  }

char readNextChar(struct Lexer* l) {
  moveCursorLexer(l);
  l->ch = readCurrentChar(l);
  return l->ch;
}

struct Lexer newLexer(const char* input) {
  struct Lexer l;
  l.input = input;
  l.input_length = strlen(input);
  l.position = 0;
  l.readPosition = 0;
  l.ch = readCurrentChar(&l);
  return l;
}


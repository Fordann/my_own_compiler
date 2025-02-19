#include <string.h>
#include <assert.h>
#include "stdio.h"
#include "lexer.h"
#include "../utils/utils.h"


//ne supporte que les caractères ASCII
char readCurrentChar(struct Lexer* l) {
  if (l->position >= l->input_length ) { 
    l->ch = 0;
  }
  else {
    l->ch = l->input[l->position];
  }
  return l->ch;
}

int readNextWord(struct Lexer* l, struct Tree* t, char* result_word) {
  if (moveCursorUntilChar(l) == ERROR)
    return ERROR;

  int letter = 0;  
  while ((l->position < strlen(l->input)) && isValidNextChar(t, result_word, l->ch)) {
    result_word[letter] = l->ch;
    letter++;
    result_word[letter] = 0;
    loadNextChar(l);
  }
  return strcmp(result_word, "") == 0;
}


int moveCursorUntilChar(struct Lexer* l) {
  while ((l->position <= l->input_length) && (!isChar(readCurrentChar(l)))) {
    if (l->position > l->input_length)
      return ERROR;
    moveCursorLexer(l);
  }
  readCurrentChar(l);
  return SUCCESS;
}


void moveCursorLexer(struct Lexer* l) {
  l->position++;
}

char lookAHead(const struct Lexer* l, int steps) {
  //assert (((l->readPosition + steps < 0) || (l->readPosition + steps > l->input_length))) && "lookAHead is trying to look out of the boundaries of the program";
  return l->input[l->position + steps];
  }

void loadNextChar(struct Lexer* l) {
  moveCursorLexer(l);
  readCurrentChar(l);
}

void print_input_lexer(struct Lexer* l) {
  for (int i = l->position; i < (int)strlen(l->input); i++) {
    printf("%c", l->input[i]);
  }
  printf("\n");
}


struct Lexer newLexer(const char* input) {
  struct Lexer l;
  l.input = input;
  l.input_length = strlen(input);
  l.position = 0;
  l.ch = readCurrentChar(&l);
  return l;
}


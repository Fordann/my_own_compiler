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

int readCurrentWord(struct Lexer* l, char* result_word) {
  int w_length = 0;
  if (l->ch == '!' || l->ch == '=') {
    result_word[0] = l->ch;
    loadNextChar(l);
    w_length++;

    if (l->ch == '=') {
      result_word[w_length] = l->ch;
      loadNextChar(l);
      w_length++;
    }
  }
  else if (isSpecialChar(l->ch)) {
    result_word[0] = l->ch;
    loadNextChar(l);
    w_length++;
  }
  else {
    while (!isSpecialChar(l->ch) && l->ch != ' ') {
        result_word[w_length] = l->ch;
        loadNextChar(l);
        w_length++;
      }
  }
  result_word[w_length] = 0;
  return w_length == 0 ? ERROR : SUCCESS;
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

int readNextWord(struct Lexer* l, char* result_word) {
  if (moveCursorUntilChar(l) == ERROR)
    return ERROR;

  readCurrentWord(l, result_word);
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


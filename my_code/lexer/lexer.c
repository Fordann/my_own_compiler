#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "lexer.h"


//ne supporte que les caractères ASCII
char readCurrentChar(const struct Lexer* l) {
  if (l->readPosition >= l->input_length ) { 
    return 0;
  }
  else {
    return l->input[l->readPosition];
  }
}

int isChar(const char* result_word) {
  return (strlen(result_word) > 1); 
}

int isSpecialChar(char ch) {
    switch (ch) {
      case ' ':
      case '=':
      case ';':
      case '(':
      case ')':
      case ',':
      case '+':
      case '{':
      case '}':
      case 0:
        return EXIT_SUCCESS;
      default:
        return EXIT_FAILURE;
    }
}

int isNumber(const char* result_word) {
  for (int i = 0; i < strlen(result_word); i++) {
    if (!('0' <= result_word[i] && result_word[i] <= '9'))
      return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

void readCurrentWord(struct Lexer* l, char* result_word) {
  int word_length = 0;

  if (isSpecialChar(l->ch) == EXIT_SUCCESS) {
    result_word[0] = l->ch;
    word_length++;
  }

  while (isSpecialChar(l->ch) == EXIT_FAILURE) {
    result_word[word_length] = l->ch;
    readNextChar(l);
    word_length++;
  }
  result_word[word_length] = 0;
}

void moveCursorUntilChar(struct Lexer* l) {
  while ( readCurrentChar(l) == ' ') {
    moveCursorLexer(l);
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

void readNextChar(struct Lexer* l) {
  moveCursorLexer(l);
  l->ch = readCurrentChar(l);
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


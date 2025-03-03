#ifndef LEXER_H
#define LEXER_H
#include "../tree/tree.h"

#define MAX_SIZE_WORD 10
#ifndef SUCCESS
#define SUCCESS 1
#endif
#ifndef ERROR 
#define ERROR 0
#endif

struct Lexer {
  const char* input; 
  int input_length;
  int position; // current position in input (points to current char)
  int readPosition; // current reading position in input (after current char)
  char ch; // current char under examination
};

struct Lexer newLexer(const char* input);

void loadNextChar(struct Lexer* l);

char lookAHead(const struct Lexer* l, int steps);

void moveCursorLexer(struct Lexer* l);

int moveCursorUntilChar(struct Lexer* l);

int readNextWord(struct Lexer* l, struct Tree* t, char* result_word);

int readCurrentWord(struct Lexer* l, char* result_word);

void print_input_lexer(struct Lexer* l);

int readNextWordV2(struct Lexer* l, struct Tree* t, char* result_word);

#endif

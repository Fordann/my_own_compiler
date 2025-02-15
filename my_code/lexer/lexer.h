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

char readNextChar(struct Lexer* l);

char lookAHead(const struct Lexer* l, int steps);

void moveCursorLexer(struct Lexer* l);

void moveCursorUntilChar(struct Lexer* l);

void readNextWord(struct Lexer* l, char* result_word);


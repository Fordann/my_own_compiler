#define MAX_SIZE_WORD 10

struct Lexer {
  const char* input; 
  int input_length;
  int position; // current position in input (points to current char)
  int readPosition; // current reading position in input (after current char)
  char ch; // current char under examination
};

struct Lexer newLexer(const char* input);

char readCurrentChar(const struct Lexer* l);

void readNextChar(struct Lexer* l);

char lookAHead(const struct Lexer* l, int steps);

void moveCursorLexer(struct Lexer* l);

void moveCursorUntilChar(struct Lexer* l);

void readCurrentWord(struct Lexer* l, char* result_word);

void readNextWord(struct Lexer* l, char* result_word);

int isChar(const char* result_word);

int isNumber(const char* result_word);

int isSpecialChar(char ch);

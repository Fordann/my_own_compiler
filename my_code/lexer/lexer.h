
struct Lexer {
  char* input; 
  int input_length;
  int position; // current position in input (points to current char)
  int readPosition; // current reading position in input (after current char)
  char ch; // current char under examination
};

struct Lexer* newLexer(char* input);

char readCurrentChar(struct Lexer* l);

void readNextChar(struct Lexer* l);

char lookAHead(struct Lexer* l, int steps);

void moveCursorLexer(struct Lexer* l);

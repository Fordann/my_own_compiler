
struct Lexer {
  char* input; 
  int position; // current position in input (points to current char)
  int readPosition; // current reading position in input (after current char)
  char ch; // current char under examination
};

struct Lexer* newLexer(char* input);

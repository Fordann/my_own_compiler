  #include "../lexer/lexer.h"
  #include "../token/token.h"
  #include <string.h>
  #include <stdio.h>


int main() {
  
  struct Tree* t = createTreeParser();
  //displayTree(t, 0);
  struct Lexer l = newLexer("letfive=5;"
    "letten=10;"
    "fori inrange(1,20):"
    " i+=1"
    "letadd=fn(x,y){"
    "x+y;               "
    "};                   \n"
    "letresult=add(five, ten);\n"
    "!-/*5;               \n"
    "5<10>5;          \n"
    "if(5<10){        \n"
    "returntrue;         \n"
    "}else{             \n"
    "returnfalse;        \n"
    "}                    \n"
    "10==10;            \n"
    "10!= 9;             \n"
   );
  char word[20];
  word[0] = 0;
  while (l.position < strlen(l.input)) {
    readNextWord(&l, t, word);
    printf("%s\t", getTokenFromLitteral(word).literal);
    word[0] = 0;
  }
  printf("\n");
  return 0;
}

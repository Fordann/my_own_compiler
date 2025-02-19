  #include "../lexer/lexer.h"
  #include "../token/token.h"
  #include <stdio.h>


int main() {
  struct Tree* t = initEmptyTree();
  addChildTree(t, initEmptyTreeForSearch());

  #define NB_SYMB 23
  struct Token tab[NB_SYMB] = {
        newToken(EQ, "="),
        newToken(LT, "<"),
        newToken(GT, ">"),
        newToken(COMMA, ";"),
        newToken(FUNCTION, "("),
        newToken(FUNCTION, ")"),
        newToken(FUNCTION, ","),
        newToken(FUNCTION, "!"),
        newToken(FUNCTION, "+"),
        newToken(FUNCTION, "-"),
        newToken(FUNCTION, "/"),
        newToken(FUNCTION, "*"),
        newToken(FUNCTION, "{"),
        newToken(FUNCTION, "}"),
        newToken(FUNCTION, "function"),
        newToken(FUNCTION, "let"),
        newToken(FUNCTION, "return"),
        newToken(FUNCTION, "true"),
        newToken(FUNCTION, "false"),
        newToken(FUNCTION, "if"),
        newToken(FUNCTION, "else"),
        newToken(FUNCTION, "!="),
        newToken(FUNCTION, "=="),
  };
  for (int i = 0; i < NB_SYMB; i++) {
    addBranchInTree(t, tab[i]);
  }

  displayTree(initEmptyTreeForSearch(), 0);
  displayTree(t, 0);
  
 // for (int i = 0; i < NB_SYMB; i++) {
 //   addBranchInTree(t, tab[i]);
 // }
 // printf("valid : %d\n", isValidNextChar(t, "fun", 'c'));
 // printf("valid : %d\n", isValidNextChar(t, "f", 'a'));
 // printf("valid : %d\n", isValidNextChar(t, "=", '='));
 // printf("valid : %d\n", isValidNextChar(t, "let", 'p'));
 // printf("valid : %d\n", isValidNextChar(t, "", 'p'));
 // displayTree(t, 0);
  char result_word[100];
  result_word[0] = 0;
  struct Lexer l = newLexer("(test");
  readNextWordV2(&l, t, result_word);
  printf("resultat : %s vs %s\n", result_word, "test");
  result_word[0] = 0;
  readNextWordV2(&l, t, result_word);
  printf("resultat : %s vs %s\n", result_word, "test");
  l = newLexer("functiontest");
  result_word[0] = 0;
  readNextWordV2(&l, t, result_word);
  printf("resultat : %s vs %s\n", result_word, "function");
  return 0;
}

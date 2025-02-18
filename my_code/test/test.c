#include <stdlib.h>
#include <stdio.h>
#include "test.h"
#include "test_lexer.h"
#include "test_token.h"
#include "test_utils.h"
#include "../token/token.h"
#include "../lexer/lexer.h"
#include "../tree/tree.h"

struct Test* createTest(char* test_name, const TTest* test_func) {
  struct Test* t = malloc(sizeof(struct Test));
  t->test_id = tcase_create(test_name);
  t->test_func = test_func;
  return t;
}

void freeTests(struct Test** tab_test, int size) {
  for (int i = 0; i < size; i++) {
    free(tab_test[i]->test_id);
    free(tab_test[i]);
  }
}

#define NB_FILE_TO_TEST 3

int main() {
  //char result_word[100];
  //struct Lexer l = newLexer("(test");
  //print_input_lexer(&l);
  //readNextWord(&l, result_word);
  //print_input_lexer(&l);
  //readNextWord(&l, result_word);
  //printf("resultat : %s vs %s\n", result_word, "test");
// char w[100];
  
//  l = newLexer("==i");

 // l = newLexer("test==");

  //l = newLexer("(test");
  //struct Lexer l = newLexer("let five = 5;"
    //"let ten = 10;\n"
    //"let add = fn(x, y) {\n"
    //"x + y;               \n"
    //"};                   \n"
    //"let result = add(five, ten);\n"
    //"!-/*5;               \n"
    //"5 < 10 > 5;          \n"
    //"if (5 < 10) {        \n"
    //"return true;         \n"
    //"} else {             \n"
    //"return false;        \n"
    //"}                    \n"
    //"10 == 10;            \n"
    //"10 != 9;             \n"
   // );

//  while (readCurrentWord(&l, w)) {
 //   printf("word : %s, token : %s len:%d\n", w, getTokenFromLitteral(w).literal, (int)strlen(w));
  struct Tree* t = initEmptyTree();
  #define NB_SYMB 23
  char* tab[NB_SYMB] = {
        "=",
        "<",
        ">",
        ";",
        "(",
        ")",
        ",",
        "!",
        "+",
        "-",
        "/",
        "*",
        "{",
        "}",
        "function",
        "let",
        "return",
        "true",
        "false",
        "if",
        "else",
        "!=",
        "=="
  };
  addBranchInTree(t, "=");
  displayTree(t, 0);
  for (int i = 0; i < NB_SYMB; i++) {
    addBranchInTree(t, tab[i]);
  }
  printf("valid : %d\n", isValidNextChar(t, "fun", 'c'));
  printf("valid : %d\n", isValidNextChar(t, "f", 'a'));
  printf("valid : %d\n", isValidNextChar(t, "=", '='));
  printf("valid : %d\n", isValidNextChar(t, "let", 'p'));
  displayTree(t, 0);
  SRunner* test_tab[NB_FILE_TO_TEST] = {
    srunner_create(test_lexer()),
    srunner_create(test_utils()),
    srunner_create(test_token()),
  };

  for (int i = 0; i < NB_FILE_TO_TEST; i++) {
    srunner_run_all(test_tab[i], CK_NORMAL);
    srunner_ntests_failed(test_tab[i]);
    srunner_free(test_tab[i]);
  }

  return 0;
}

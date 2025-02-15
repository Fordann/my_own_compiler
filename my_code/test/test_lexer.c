#include <assert.h>
#include <stdio.h>
#include "test.h"
#include "../lexer/lexer.h"
#include "../token/token.h"
#include "test_lexer.h"


START_TEST (testReadNextWord) 
{
  char result_word[20];
  struct Lexer l = newLexer("test");
  readNextWord(&l, result_word);
  ck_assert_str_eq(result_word, "test");

  l = newLexer("test1 test2");
  readNextWord(&l, result_word);
  ck_assert_str_eq(result_word, "test1");

  l = newLexer("(test");
  readNextWord(&l, result_word);
  ck_assert_str_eq(result_word, "(\0");

  l = newLexer("test1(test2");
  readNextWord(&l, result_word);
  ck_assert_str_eq(result_word, "test1");
}
END_TEST

START_TEST (testMoveCursorUntilChar) 
{
  struct Lexer l = newLexer("test");
  moveCursorUntilChar(&l);
  ck_assert_int_eq(l.ch=='t', SUCCESS);

  l = newLexer("\n\r\ta");
  moveCursorUntilChar(&l);
  ck_assert_int_eq(l.ch=='a', SUCCESS);


}
END_TEST

#define NB_TEST_LEXER 2

Suite *test_lexer(void) {
  Suite *s = suite_create("test_lexer");
   
  struct Test* testTab[NB_TEST_LEXER] = {
    createTest("nextWord", testReadNextWord),
    createTest("moveUntilChar", testMoveCursorUntilChar),
  };

  for (int i = 0; i < NB_TEST_LEXER; i++) {
    struct Test* t = testTab[i];
    tcase_add_test(t->test_id, t->test_func);
    suite_add_tcase(s, t->test_id);
  }
  //freeTests(testTab, NB_TEST_LEXER);

  return s;
}

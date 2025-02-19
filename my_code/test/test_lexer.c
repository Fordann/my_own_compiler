#include <assert.h>
#include <stdio.h>
#include "test.h"
#include "../lexer/lexer.h"
#include "../tree/tree.h"
#include "../token/token.h"
#include "test_lexer.h"
#include <stdlib.h>


START_TEST (testReadNextWord) 
{
  struct Tree* t = createTreeParser();

  char result_word[20];
  result_word[0] = 0;

  struct Lexer l = newLexer("test");
  readNextWord(&l, t, result_word);
  ck_assert_str_eq(result_word, "test");
  result_word[0] = 0;

  l = newLexer("01==");
  readNextWord(&l, t, result_word);
  ck_assert_str_eq(result_word, "01");
  result_word[0] = 0;

  l = newLexer("test1 test2");
  readNextWord(&l, t, result_word);
  ck_assert_str_eq(result_word, "test1");
  result_word[0] = 0;

  l = newLexer("(test");
  readNextWord(&l, t, result_word);
  ck_assert_str_eq(result_word, "(");
  result_word[0] = 0;

  l = newLexer("test=");
  readNextWord(&l, t, result_word);
  ck_assert_str_eq(result_word, "test");
  result_word[0] = 0;

  l = newLexer("test==");
  readNextWord(&l, t, result_word);
  ck_assert_str_eq(result_word, "test");
  result_word[0] = 0;

  l = newLexer("==i");
  readNextWord(&l, t, result_word);
  ck_assert_str_eq(result_word, "==");
  result_word[0] = 0;

  l = newLexer("test!");
  readNextWord(&l, t, result_word);
  ck_assert_str_eq(result_word, "test");
  result_word[0] = 0;

  l = newLexer("test1!");
  readNextWord(&l, t, result_word);
  ck_assert_str_eq(result_word, "test1");
  result_word[0] = 0;

  l = newLexer("=i");
  readNextWord(&l, t, result_word);
  ck_assert_str_eq(result_word, "=");
  result_word[0] = 0;

  l = newLexer("!=");
  readNextWord(&l, t, result_word);
  ck_assert_str_eq(result_word, "!=");
  result_word[0] = 0;

  l = newLexer("!?");
  readNextWord(&l, t, result_word);
  ck_assert_str_eq(result_word, "!");
  result_word[0] = 0;

  l = newLexer("test1 test2");
  readNextWord(&l, t, result_word);
  result_word[0] = 0;
  readNextWord(&l, t, result_word);
  ck_assert_str_eq(result_word, "test2");
  result_word[0] = 0;

  l = newLexer("==i");
  readNextWord(&l, t, result_word);
  result_word[0] = 0;
  readNextWord(&l, t, result_word);
  ck_assert_str_eq(result_word, "i");
  result_word[0] = 0;

  l = newLexer("01\n1==");
  readNextWord(&l, t, result_word);
  result_word[0] = 0;
  readNextWord(&l, t, result_word);
  ck_assert_str_eq(result_word, "1");
  result_word[0] = 0;

  l = newLexer("test==");
  readNextWord(&l, t, result_word);
  result_word[0] = 0;
  readNextWord(&l, t, result_word);
  ck_assert_str_eq(result_word, "==");
  result_word[0] = 0;

  l = newLexer("(test");
  readNextWord(&l, t, result_word);
  result_word[0] = 0;
  readNextWord(&l, t, result_word);
  ck_assert_str_eq(result_word, "test");
  result_word[0] = 0;

  l = newLexer("functiontest");
  readNextWord(&l, t, result_word);
  result_word[0] = 0;
  readNextWord(&l, t, result_word);
  ck_assert_str_eq(result_word, "test");
  result_word[0] = 0;
}

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

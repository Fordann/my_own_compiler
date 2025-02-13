#include <stdlib.h>
#include <assert.h>
#include <check.h>
#include "test.h"
#include "../lexer/lexer.h"
#include "../token/token.h"
#include <stdio.h>


START_TEST (testReadNextWord) 
{
  char result_word[20];
  struct Lexer l = newLexer("test");
  readCurrentWord(&l, result_word);
  printf("%s\n", result_word);
  ck_assert_str_eq(result_word, "test");

  l = newLexer("test1 test2");
  readCurrentWord(&l, result_word);
  ck_assert_str_eq(result_word, "test1");

  l = newLexer("(test");
  readCurrentWord(&l, result_word);
  ck_assert_str_eq(result_word, "(\0");

  l = newLexer("test1(test2");
  readCurrentWord(&l, result_word);
  ck_assert_str_eq(result_word, "test1");
}
END_TEST

START_TEST (testIsNumber) 
{
  ck_assert_int_eq(isNumber("99a"), EXIT_FAILURE);
  ck_assert_int_eq(isNumber("a"), EXIT_FAILURE);
  ck_assert_int_eq(isNumber("10"), EXIT_SUCCESS);
  ck_assert_int_eq(isNumber("0"), EXIT_SUCCESS);
}
END_TEST

START_TEST (testIsSpecialChar) 
{
  ck_assert_int_eq(isSpecialChar('('), EXIT_SUCCESS);
  ck_assert_int_eq(isSpecialChar(')'), EXIT_SUCCESS);
  ck_assert_int_eq(isSpecialChar('{'), EXIT_SUCCESS);
  ck_assert_int_eq(isSpecialChar('}'), EXIT_SUCCESS);
  ck_assert_int_eq(isSpecialChar(','), EXIT_SUCCESS);
  ck_assert_int_eq(isSpecialChar('+'), EXIT_SUCCESS);
  ck_assert_int_eq(isSpecialChar('='), EXIT_SUCCESS);
  ck_assert_int_eq(isSpecialChar(';'), EXIT_SUCCESS);
  ck_assert_int_eq(isSpecialChar('a'), EXIT_FAILURE);
  ck_assert_int_eq(isSpecialChar(' '), EXIT_SUCCESS);
  ck_assert_int_eq(isSpecialChar(0), EXIT_SUCCESS);
  ck_assert_int_eq(isSpecialChar('0'), EXIT_FAILURE);
}
END_TEST
#define NB_TEST 3

Suite *test_lexer(void) {
  Suite *s = suite_create("test_lexer");
   
  struct Test* testTab[NB_TEST] = {
    createTest("Number", testIsNumber),
    createTest("SpecialChar", testIsSpecialChar),
    createTest("nextWord", testReadNextWord)
  };

  for (int i = 0; i < NB_TEST; i++) {
    struct Test* t = testTab[i];
    tcase_add_test(t->test_id, t->test_func);
    suite_add_tcase(s, t->test_id);
  }

  return s;
}
int main() {
    Suite *s = test_lexer();
    SRunner *sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    //int failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return 0;
}

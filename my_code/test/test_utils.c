#include <check.h>
#include <stdio.h>
#include "test.h"
#include "../utils/utils.h"

START_TEST (testIsNumber) 
{
  ck_assert_int_eq(isNumber("99a"), ERROR);
  ck_assert_int_eq(isNumber("a"), ERROR);
  ck_assert_int_eq(isNumber("10"), SUCCESS);
  ck_assert_int_eq(isNumber("0"), SUCCESS);
}
END_TEST

START_TEST (testIsChar) 
{
  ck_assert_int_eq(isChar('A'), SUCCESS);
  ck_assert_int_eq(isChar('a'), SUCCESS);
  ck_assert_int_eq(isChar(')'), SUCCESS);
  ck_assert_int_eq(isChar('1'), SUCCESS);
  ck_assert_int_eq(isChar('}'), SUCCESS);
  ck_assert_int_eq(isChar(','), SUCCESS);
  ck_assert_int_eq(isChar('+'), SUCCESS);
  ck_assert_int_eq(isChar('.'), ERROR);
  ck_assert_int_eq(isChar(';'), SUCCESS);
  ck_assert_int_eq(isChar(' '), ERROR);
  ck_assert_int_eq(isChar('\n'), ERROR);
  ck_assert_int_eq(isChar('\t'), ERROR);
  ck_assert_int_eq(isChar('\r'), ERROR);
  ck_assert_int_eq(isChar(EOF), ERROR);
  ck_assert_int_eq(isChar(0), SUCCESS);
}
END_TEST
START_TEST (testIsSpecialChar) 
{
  ck_assert_int_eq(isSpecialChar('('), SUCCESS);
  ck_assert_int_eq(isSpecialChar(')'), SUCCESS);
  ck_assert_int_eq(isSpecialChar('{'), SUCCESS);
  ck_assert_int_eq(isSpecialChar('}'), SUCCESS);
  ck_assert_int_eq(isSpecialChar(','), SUCCESS);
  ck_assert_int_eq(isSpecialChar('+'), SUCCESS);
  ck_assert_int_eq(isSpecialChar('='), SUCCESS);
  ck_assert_int_eq(isSpecialChar(';'), SUCCESS);
  ck_assert_int_eq(isSpecialChar('a'), ERROR);
  ck_assert_int_eq(isSpecialChar(' '), ERROR);
  ck_assert_int_eq(isSpecialChar(0), SUCCESS);
  ck_assert_int_eq(isSpecialChar('0'), ERROR);
}
END_TEST

#define NB_TEST_UTILS 3

Suite *test_utils(void) {
  Suite *s = suite_create("test_utils");
   
  struct Test testTab[NB_TEST_UTILS] = {
    createTest("Number", testIsNumber),
    createTest("SpecialChar", testIsSpecialChar),
    createTest("isChar", testIsChar)

  };

  for (int i = 0; i < NB_TEST_UTILS; i++) {
    struct Test t = testTab[i];
    tcase_add_test(t.test_id, t.test_func);
  suite_add_tcase(s, t.test_id);
  }
  return s;
}

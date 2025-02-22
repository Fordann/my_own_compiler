#include <check.h>
#include "test.h"
#include "../token/token.h"



START_TEST (testGetTokenFromLitteral) 
{
  
  ck_assert_int_eq(getTokenFromLitteral("let").type == LET, SUCCESS);
  ck_assert_int_eq(getTokenFromLitteral("function").type == FUNCTION, SUCCESS);  
  ck_assert_int_eq(getTokenFromLitteral("if").type == IF, SUCCESS);  
  ck_assert_int_eq(getTokenFromLitteral("else").type == ELSE, SUCCESS);  
  ck_assert_int_eq(getTokenFromLitteral("true").type == TRUE, SUCCESS);  
  ck_assert_int_eq(getTokenFromLitteral("false").type == FALSE, SUCCESS);  
  ck_assert_int_eq(getTokenFromLitteral("return").type == RETURN, SUCCESS);  
  ck_assert_int_eq(getTokenFromLitteral("<").type == LT, SUCCESS);  
  ck_assert_int_eq(getTokenFromLitteral(">").type == GT, SUCCESS);  
  ck_assert_int_eq(getTokenFromLitteral("==").type == EQ, SUCCESS);  
  ck_assert_int_eq(getTokenFromLitteral("!=").type == NOT_EQ, SUCCESS);  
  ck_assert_int_eq(getTokenFromLitteral("!").type == BANG, SUCCESS);  
  ck_assert_int_eq(getTokenFromLitteral("(").type == LPAREN, SUCCESS);  
  ck_assert_int_eq(getTokenFromLitteral(")").type == RPAREN, SUCCESS);  
  ck_assert_int_eq(getTokenFromLitteral("{").type == LBRACE, SUCCESS);  
  ck_assert_int_eq(getTokenFromLitteral("}").type == RBRACE, SUCCESS);  
  ck_assert_int_eq(getTokenFromLitteral(";").type == SEMICOLON, SUCCESS);  
  ck_assert_int_eq(getTokenFromLitteral("+").type == PLUS, SUCCESS);  
  ck_assert_int_eq(getTokenFromLitteral("*").type == MULT, SUCCESS);  
  ck_assert_int_eq(getTokenFromLitteral("/").type == DIV, SUCCESS);  
  ck_assert_int_eq(getTokenFromLitteral("-").type == MINUS, SUCCESS);  
  ck_assert_int_eq(getTokenFromLitteral(",").type == COMMA, SUCCESS);  
  ck_assert_int_eq(getTokenFromLitteral("3").type == INT_TOK, SUCCESS);  
  ck_assert_int_eq(getTokenFromLitteral("10").type == INT_TOK, SUCCESS);  
  ck_assert_int_eq(getTokenFromLitteral("10a").type == IDENT, SUCCESS);  
  ck_assert_int_eq(getTokenFromLitteral("abcd").type == IDENT, SUCCESS);  
}
END_TEST

#define NB_TEST_TOKEN 1

Suite *test_token(void) {
  Suite *s = suite_create("test_token");
   
  struct Test testTab[NB_TEST_TOKEN] = {
    createTest("getGetTokenFromLitteral", testGetTokenFromLitteral)

  };

  for (int i = 0; i < NB_TEST_TOKEN; i++) {
    struct Test t = testTab[i];
    tcase_add_test(t.test_id, t.test_func);
    suite_add_tcase(s, t.test_id);
  }

  return s;
}

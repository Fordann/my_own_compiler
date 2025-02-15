#include <stdlib.h>
#include <stdio.h>
#include "test.h"
#include "test_lexer.h"
#include "test_token.h"
#include "test_utils.h"
#include "../token/token.h"

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

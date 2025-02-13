#include <stdlib.h>
#include "test.h"

struct Test* createTest(char* test_name, const TTest* test_func) {
  struct Test* t = malloc(sizeof(struct Test));
  t->test_id = tcase_create(test_name);
  t->test_func = test_func;
  return t;
}

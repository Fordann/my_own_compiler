#include <check.h>

struct Test {
  struct TCase* test_id;
  const TTest* test_func;
  
};

struct Test* createTest(char* test_name, const TTest*);

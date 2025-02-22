#include <check.h>

#ifndef SUCCESS
#define SUCCESS 1
#endif
#ifndef ERROR 
#define ERROR 0
#endif

struct Test {
  struct TCase* test_id;
  const TTest* test_func;
  
};

struct Test createTest(char* test_name, const TTest*);

void freeTests(struct Test** tab_test, int size);


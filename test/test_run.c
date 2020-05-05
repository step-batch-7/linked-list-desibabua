#include <stdio.h>
#include "test_list.h"

void run_all_test(void)
{
  new_test();
  printf("hello_world\n");
}

int main()
{
  run_all_test();
  return 0;
}
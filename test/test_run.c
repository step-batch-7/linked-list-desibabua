#include "test_list.h"

void run_all_test(void)
{
  test_create_node();
  test_create_list();
}

int main()
{
  run_all_test();
  return 0;
}
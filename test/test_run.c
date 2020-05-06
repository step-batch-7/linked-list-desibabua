#include "test_list.h"

void run_all_test(void)
{
  test_create_node();
  test_create_list();
  test_add_to_end();
  test_add_to_start();
  test_insert_at();
  test_is_in_list();
  test_add_unique();
  test_remove_from_start();
  test_remove_from_end();
  test_remove_at();
  test_remove_first_occurrence();
  test_remove_all_occurrences();
  test_clear_list();
}

int main()
{
  run_all_test();
  return 0;
}
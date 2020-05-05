#include <stdio.h>
#include "../list.h"
#include "test_list.h"

void print_message(int flag,char *message)
{
  char symbol = 'F';
  if (flag)
  {
    symbol = 'P';
  }
  printf("%c  %s\n", symbol, message);
}

void assert_num(int *prev_test, int num1,int num2)
{
  *prev_test = *prev_test && (num1 == num2);
}

void assert_pointer(int *prev_test, void *ptr1,void *ptr2)
{
  *prev_test = *prev_test && (ptr1 == ptr2);
}

void test_create_node(void)
{
  Node_ptr node = create_node(4);
  int result;
  assert_num(&result, node->value, 4);
  assert_pointer(&result, node->next, NULL);
  print_message(result, "should return a node having value and a pointer to null");
}
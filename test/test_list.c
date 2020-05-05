#include <stdio.h>
#include <stdlib.h>
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
  int result = 1;
  assert_num(&result, node->value, 4);
  assert_pointer(&result, node->next, NULL);
  print_message(result, "should create a node having value and a next pointing to null");
  free(node);
}

void test_create_list(void)
{
  List_ptr list = create_list();
  int result = 1;
  assert_pointer(&result, list->head, NULL);
  assert_pointer(&result, list->last, NULL);
  assert_num(&result, list->count, 0);
  print_message(result, "should create a empty list having head and last pointing to null and count as 0");
  destroy_list(list);
}
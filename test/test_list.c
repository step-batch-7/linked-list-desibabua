#include <stdio.h>
#include <stdlib.h>
#include "../list.h"
#include "test_list.h"

void assert_num(int num1,int num2, char *message)
{
  char symbol = num1 == num2 ? 'P' : 'F';
  printf("  %c  %s\n", symbol, message);
}

void assert_pointer(void *ptr1,void *ptr2, char *message)
{
  char symbol = ptr1 == ptr2 ? 'P' : 'F';
  printf("  %c  %s\n", symbol, message);
}

void test_create_node(void)
{
  printf("# create_node\n");

  Node_ptr node = create_node(4);
  assert_num(node->value, 4, "  should give the right value");
  assert_pointer(node->next, NULL, "  next should point to null");

  free(node);
  print_empty_line;
}

void test_create_list(void)
{
  printf("# create_list\n");

  List_ptr list = create_list();
  assert_pointer(list->head, NULL, "  head should point to null");
  assert_pointer(list->last, NULL, "  last should point to null");
  assert_num(list->count, 0, "  count should be zero");

  destroy_list(list);
  print_empty_line;
}
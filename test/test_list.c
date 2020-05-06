#include <stdio.h>
#include <stdlib.h>
#include "../list.h"
#include "test_list.h"

void assert_num(int num1,int num2, char *message)
{
  char symbol = num1 == num2 ? 'P' : 'F';
  printf("    %c  %s\n", symbol, message);
}

void assert_is_eq_ptr(void *ptr1,void *ptr2, char *message)
{
  char symbol = ptr1 == ptr2 ? 'P' : 'F';
  printf("    %c  %s\n", symbol, message);
}

void assert_is_not_eq_ptr(void *ptr1,void *ptr2, char *message)
{
  char symbol = ptr1 != ptr2 ? 'P' : 'F';
  printf("    %c  %s\n", symbol, message);
}

void describe(char *function_name)
{
  printf("\n # %s\n\n", function_name);
}

void it(char *testing_message)
{
  printf("  * %s\n", testing_message);
}

void test_create_node(void)
{
  describe("create_node");
  it("should create a node");

  Node_ptr node = create_node(4);
  assert_num(node->value, 4, "should give the right value");
  assert_is_eq_ptr(node->next, NULL, "next should point to null");
  print_empty_line;

  free(node);
}

void test_create_list(void)
{
  describe("create_list");
  it("should create a empty list");

  List_ptr list = create_list();
  assert_is_eq_ptr(list->head, NULL, "head should point to null");
  assert_is_eq_ptr(list->last, NULL, "last should point to null");
  assert_num(list->count, 0, "count should be zero");
  print_empty_line;

  destroy_list(list);
}

void test_add_to_end()
{
  describe("add_to_end");

  List_ptr list = create_list();
  add_to_end(list, 2);

  it("should add a number to a empty list at end");
  assert_is_not_eq_ptr(list->head, NULL, "head should not point to null");
  assert_is_eq_ptr(list->head, list->last, "head and last should point to same node");
  assert_num(list->head->value, 2, "value of node should be correct");
  assert_num(list->count, 1, "count should be one");
  print_empty_line;

  add_to_end(list, 4);

  it("should add a number to a list of length 1 at end");
  assert_is_not_eq_ptr(list->head, NULL, "head should not point to null");
  assert_is_not_eq_ptr(list->head, list->last, "head and last should point to same");
  assert_is_eq_ptr(list->last, list->head->next, "last should point to correct node");
  assert_num(list->head->value, 2, "value of first node should be correct");
  assert_num(list->head->next->value, 4, "value of second node should be correct");
  assert_num(list->count, 2, "count should be two");
  print_empty_line;

  destroy_list(list);
}
#include <stdio.h>
#include <stdlib.h>
#include "../list.h"
#include "test_list.h"
#include "assert.h"

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
  assert_is_eq_ptr(list->last->next, NULL, "last's next should point to null");
  print_empty_line;

  destroy_list(list);
}

void test_add_to_start(void)
{
  describe("add_to_start");

  List_ptr list = create_list();
  add_to_start(list, 2);

  it("should add a number to an empty list at start");
  assert_is_not_eq_ptr(list->head, NULL, "head should not point to null");
  assert_is_eq_ptr(list->head, list->last, "head and last should point to same node");
  assert_num(list->head->value, 2, "value of node should be correct");
  assert_num(list->count, 1, "count should be one");
  print_empty_line;

  add_to_start(list, 4);

  it("should add a number to a list of length 1 at start");
  assert_is_not_eq_ptr(list->head, NULL, "head should not point to null");
  assert_is_not_eq_ptr(list->head, list->last, "head and last should not point to same");
  assert_is_eq_ptr(list->last, list->head->next, "last should point to correct node");
  assert_num(list->head->value, 4, "value of first node should be correct");
  assert_num(list->head->next->value, 2, "value of second node should be correct");
  assert_num(list->count, 2, "count should be two");
  assert_is_eq_ptr(list->last->next, NULL, "last's next should point to null");
  print_empty_line;

  destroy_list(list);
}

void test_insert_at(void)
{
  describe("insert_at");

  List_ptr list = create_list();
  Status status;
  status = insert_at(list, 2, 0);

  it("should add a number to an empty list");
  assert_is_not_eq_ptr(list->head, NULL, "head should not point to null");
  assert_is_eq_ptr(list->head, list->last, "head and last should point to same node");
  assert_num(list->head->value, 2, "value of node should be correct");
  assert_num(list->count, 1, "count should be one");
  assert_num(status, Success, "status should be success");
  print_empty_line;

  status = insert_at(list, 4,1);

  it("should add a number to a list when asked to add in last position");
  assert_is_not_eq_ptr(list->head, NULL, "head should not point to null");
  assert_is_not_eq_ptr(list->head, list->last, "head and last should not point to same");
  assert_is_eq_ptr(list->last, list->head->next, "last should point to correct node");
  assert_num(list->head->value, 2, "value of first node should be correct");
  assert_num(list->head->next->value, 4, "value of second node should be correct");
  assert_num(list->count, 2, "count should be two");
  assert_is_eq_ptr(list->last->next, NULL, "last's next should point to null");
  assert_num(status, Success, "status should be success");
  print_empty_line;

  status = insert_at(list, 10,0);

  it("should add a number to a list when asked to add in first position");
  assert_is_not_eq_ptr(list->head, NULL, "head should not point to null");
  assert_is_not_eq_ptr(list->head, list->last, "head and last should not point to same");
  assert_is_eq_ptr(list->last, list->head->next->next, "last should point to correct node");
  assert_num(list->head->value, 10, "value of first node should be correct");
  assert_num(list->head->next->value, 2, "value of node between first and last should not change");
  assert_num(list->head->next->next->value, 4, "value of last node should not change");
  assert_num(list->count, 3, "count should be three");
  assert_is_eq_ptr(list->last->next, NULL, "last's next should point to null");
  assert_num(status, Success, "status should be success");
  print_empty_line;

  status = insert_at(list, 5,1);

  it("should add a number to a list when asked to add in middle");
  assert_is_not_eq_ptr(list->head, NULL, "head should not point to null");
  assert_is_not_eq_ptr(list->head, list->last, "head and last should not point to same");
  assert_is_eq_ptr(list->last, list->head->next->next->next, "last should point to correct node");
  assert_num(list->head->value, 10, "value of first node should not change");
  assert_num(list->head->next->value, 5, "value of node inserted should be correct");
  assert_num(list->head->next->next->value, 2, "value of node after inserted node should be correct");
  assert_num(list->count, 4, "count should be three");
  assert_is_eq_ptr(list->last->next, NULL, "last's next should point to null");
  assert_num(status, Success, "status should be success");
  print_empty_line;

  status = insert_at(list, 5,-1);

  it("should not add a number to a list when asked to add position less than zero");
  assert_is_not_eq_ptr(list->head, NULL, "head should not point to null");
  assert_num(list->head->value, 10, "value of first node should not change");
  assert_num(list->last->value, 4, "value of last node should not change");
  assert_num(list->count, 4, "count should be three");
  assert_is_eq_ptr(list->last->next, NULL, "last's next should point to null");
  assert_num(status, Failure, "status should be failure");
  print_empty_line;

  status = insert_at(list, 5,5);

  it("should not add a number to a list when asked to add position greater than count");
  assert_is_not_eq_ptr(list->head, NULL, "head should not point to null");
  assert_num(list->head->value, 10, "value of first node should not change");
  assert_num(list->last->value, 4, "value of last node should not change");
  assert_num(list->count, 4, "count should be three");
  assert_is_eq_ptr(list->last->next, NULL, "last's next should point to null");
  assert_num(status, Failure, "status should be failure");
  print_empty_line;

  destroy_list(list);
}
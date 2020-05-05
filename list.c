#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Node_ptr create_node(int value) 
{
  Node_ptr node = malloc(sizeof(Node));
  node->value = value;
  node->next = NULL;
  return node;
}

List_ptr create_list(void) 
{
  List_ptr list = malloc(sizeof(List));
  list->head = NULL;
  list->last = NULL;
  list->count = 0;
  return list;
}

Status add_to_end(List_ptr list, int value) 
{
  return insert_at(list, value, list->count);
}

Status add_to_start(List_ptr list, int value) 
{
  return insert_at(list, value, 0);
}

Status insert_at(List_ptr list, int value, int position) 
{
  if(position < 0 || position > list->count)
  {
    return Failure;
  }

  Node_ptr node = create_node(value);
  Prev_Current_Pair nodes_ptrs;
  nodes_ptrs.prev = NULL;
  nodes_ptrs.current = list->head;

  if (list->count == 0 || list->count == position)
  {
    list->last = node;
  }

  while(position != 0)
  {
    nodes_ptrs.prev = nodes_ptrs.current;
    nodes_ptrs.current = nodes_ptrs.current->next;
    position--;
  }

  Node_ptr *ptr_to_set = &list->head;
  if (nodes_ptrs.prev != NULL)
  {
    ptr_to_set = &nodes_ptrs.prev->next;
  }

  *ptr_to_set = node;
  node->next = nodes_ptrs.current;
  list->count++;
  return Success;
}

Status is_in_list(List_ptr list,int value) {
  Node_ptr p_walk = list->head;
  while (p_walk != NULL) {
    if(p_walk->value== value) {
      return Success;
    }
    p_walk = p_walk->next;
  }
  return Failure;
}

Status add_unique(List_ptr list, int value) {
  Node_ptr node;

  if (!is_in_list(list, value)) {
    return add_to_end(list, value);
  }
  return Failure;
}

Status remove_from_start(List_ptr list) 
{
  return remove_at(list, 0);
}

Status remove_from_end(List_ptr list) 
{
  return remove_at(list, list->count - 1);
}

Status remove_at(List_ptr list, int position) 
{
  if(position >= list->count || position < 0)
  {
    return Failure;
  }

  Prev_Current_Pair node_ptrs;
  node_ptrs.prev = NULL;
  node_ptrs.current = list->head;

  while(position > 0){
    node_ptrs.prev = node_ptrs.current;
    node_ptrs.current = node_ptrs.current->next;
    position--;
  }

  Node_ptr node_to_remove = node_ptrs.current;
  Node_ptr *ptr_to_set = &list->head;

  if (node_ptrs.prev != NULL)
  {
    ptr_to_set = &node_ptrs.prev->next;
  }

  *ptr_to_set = node_ptrs.current->next;
  list->count--;
  free(node_to_remove);
  return Success;
}

Status remove_first_occurrence(List_ptr list, int value) {
  Node_ptr p_walk = list->head;
  int position = 0;

  if(!is_in_list(list,value)) {
    return Failure;
  }
  while (p_walk->value != value) {
    p_walk = p_walk->next;
    position++;
  }

  return remove_at(list, position);
}

Status remove_all_occurrences(List_ptr list, int value) {
  Status status = Failure;

  while (is_in_list(list,value)) {
    status = remove_first_occurrence(list, value);
  }
  return status;
}

Status clear_list(List_ptr list) {
  Node_ptr p_walk = list->head;
  Node_ptr node_to_remove;

  while (p_walk != NULL) {
    node_to_remove = p_walk;
    p_walk = p_walk->next;
    free(node_to_remove);
  }

  list->head = NULL;
  list->last = NULL;
  list->count = 0;
  return Success;
}

void destroy_list(List_ptr list) {
  clear_list(list);
  free(list);
  list = NULL;
}

void display(List_ptr list) {
  Node_ptr p_walk = list->head;
  while (p_walk != NULL) {
    printf("%d ", p_walk->value);
    p_walk = p_walk->next;
  }
  printf("\ncount : %d\n\n",list->count);
}
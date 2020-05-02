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
  Node_ptr node = create_node(value);
  Node_ptr *ptr_to_set = &list->head;

  if (list->head != NULL) 
  {
    ptr_to_set = &list->last->next;
  }

  *ptr_to_set = node;
  list->last = node;
  list->count++;
  return Success;
}

Status add_to_start(List_ptr list, int value) {
  Node_ptr node = create_node(value);
  if (list->head == NULL)
  {
    list->last = node;
  }
  else
  {
    node->next = list->head;
  }
  list->head = node;
  list->count++;
  
  return Success;
}

Status insert_at(List_ptr list, int value, int position) 
{
  if(position < 0 || position > list->count){
    return Failure;
  }
  if(position == 0) {
    return add_to_start(list, value);
  }
  if(position == list->count) {
    return add_to_end(list, value);
  }

  int count = 1;
  Node_ptr node = create_node(value);
  Node_ptr p_walk = list->head;
  while (count != position) {
    p_walk = p_walk->next;
    count++;
  }
  node->next = p_walk->next;
  p_walk->next = node;
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

Status remove_from_start(List_ptr list) {

  if(list->head != NULL) {
    Node_ptr node_to_remove = list->head;
    list->count--;
    list->head = list->count == 0 ? NULL : list->head->next;

    free(node_to_remove);
    return Success;
  }
  return Failure;
}

Status remove_from_end(List_ptr list) {
  if(list->count <= 1) {
    return remove_from_start(list);
  }

  int count = 1;
  Node_ptr p_walk = list->head;
  while(count != (list->count-1)) {
    p_walk = p_walk->next;
    count++;
  }

  Node_ptr node_to_remove = p_walk->next;
  p_walk->next = NULL;
  list->last = p_walk;
  list->count--;

  free(node_to_remove);
  return Success;
}

Status remove_at(List_ptr list, int position) {
  if(position >= list->count){
    return Failure;
  }
  if(position <= 0) {
    return remove_from_start(list);
  }
  if(position == (list->count-1)) {
    return remove_from_end(list);
  }

  int count = 0;
  Node_ptr p_walk = list->head;
  while (count != position-1) {
    p_walk = p_walk->next;
    count++;
  }

  Node_ptr node_to_remove = p_walk->next;
  p_walk->next = node_to_remove->next;
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
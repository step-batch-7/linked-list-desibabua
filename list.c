#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Node_ptr create_node(int value) {
  Node_ptr node = malloc(sizeof(Node));
  node->value = value;
  node->next = NULL;
  return node;
}

List_ptr create_list(void){
  List_ptr list = malloc(sizeof(List));
  list->head = NULL;
  list->last = NULL;
  list->count = 0;
  return list;
}

Status add_to_end(List_ptr list, int value){
  Status status = Failure;
  Node_ptr node = create_node(value);
  if (list->head == NULL)
  {
    list->head = node;
  } else
  {
    list->last->next = node;
  }
  list->last = node;
  status = Success;
  return status;
}

Status add_to_start(List_ptr list, int value){
  Status status = Failure;
  Node_ptr node = create_node(value);
  if(list->head == NULL)
  {
    list->last = node;
  } else
  {
    node->next = list->head;
  }
  list->head = node;
  status = Success;
  return status;
}

Status insert_at(List_ptr list, int value, int position) {
  Status status = Failure;
  int count = 1;
  Node_ptr node = create_node(value);
  Node_ptr p_walk = list->head;
  while (p_walk !=NULL)
  {
    if(count == position){
      node->next = p_walk->next;
      p_walk->next = node;
      status = Success;
    }
    p_walk = p_walk->next;
    count++;
  }
  return status;
}

void display(List_ptr list) {
  Node_ptr p_walk = list->head;
  while (p_walk != NULL)
  {
    printf("%d ", p_walk->value);
    p_walk = p_walk->next;
  }
}
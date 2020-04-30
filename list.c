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
  Node_ptr node = create_node(value);
  if (list->head == NULL)
  {
    list->head = node;
  } else
  {
    list->last->next = node;
  }
  list->last = node;
  Status status = Success;
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
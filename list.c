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
  list->count++;
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
  list->count++;
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
      list->count++;
      status = Success;
    }
    p_walk = p_walk->next;
    count++;
  }
  return status;
}

Status is_value_in_list(List_ptr list,int value) {
  Status status = Failure;
  Node_ptr p_walk = list->head;
  while (p_walk != NULL)
  {
    if(p_walk->value== value)
    {
      status = Success;
    }
    p_walk = p_walk->next;
  }
  return status;
}

Status add_unique(List_ptr list, int value){
  Status status = Failure;
  Node_ptr node;
  if (!is_value_in_list(list, value))
  {
    status = add_to_end(list, value);
  }
  return status;
}

Status remove_from_start(List_ptr list) {
  Status status = Failure;
  if(list->head != NULL)
  {
    Node_ptr node_to_remove = list->head;
    list->count--;
    list->head = list->count == 0 ? NULL : list->head->next;

    free(node_to_remove);
    status = Success;
  }
  return status;
}

Status remove_from_end(List_ptr list) {
  Status status = Failure;
  int count = 1;
  Node_ptr p_walk = list->head;
  while(p_walk != NULL)
  {
    if(list->count == 1){
      status = remove_from_start(list);
      break;
    }

    if(count == (list->count-1))
    {
      Node_ptr node_to_remove = p_walk->next;
      p_walk->next = NULL;
      list->last = p_walk;
      list->count--;

      free(node_to_remove);
      status = Success;
    }
    p_walk = p_walk->next;
    count++;
  }

  return status;
}

Status remove_at(List_ptr list, int position){
  Status status = Failure;
  int count = 0;
  Node_ptr p_walk = list->head;

  while (p_walk != NULL)
  {
    if(position == 0){
      status = remove_from_start(list);
      break;
    }
    
    if(position == (list->count-1)){
      status = remove_from_end(list);
      break;
    }

    if(count == position-1){
      Node_ptr node_to_remove = p_walk->next;
      p_walk->next = node_to_remove->next;
      list->count--;

      free(node_to_remove);
      status = Success;
      break;
    }
    p_walk = p_walk->next;
    count++;
  }

  return status;
}

Status remove_first_occurrence(List_ptr list, int value){
  Status status = Failure;
  Node_ptr p_walk = list->head;
  int position = 0;

  while (p_walk != NULL)
  {
    if(p_walk->value == value)
    {
      status = remove_at(list, position);
      break;
    }
    p_walk = p_walk->next;
    position++;
  }

  return status;
}

Status remove_all_occurrences(List_ptr list, int value){
  Status status = Failure;

  while (is_value_in_list(list,value))
  {
    status = remove_first_occurrence(list, value);
  }

  return status;
}

Status clear_list(List_ptr list)
{
  Status status = Failure;
  Node_ptr p_walk = list->head;
  Node_ptr node_to_remove;

  while (p_walk != NULL)
  {
    node_to_remove = p_walk;
    p_walk = p_walk->next;
    free(node_to_remove);
  }

  list->head = NULL;
  list->last = NULL;
  list->count = 0;
  status = Success;

  return status;
}

void destroy_list(List_ptr list){
  clear_list(list);
  free(list);
}

void display(List_ptr list) {
  Node_ptr p_walk = list->head;
  while (p_walk != NULL)
  {
    printf("%d ", p_walk->value);
    p_walk = p_walk->next;
  }
  printf("\ncount : %d\n\n",list->count);
}
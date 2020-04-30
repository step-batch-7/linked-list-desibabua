#include <stdio.h>
#include "list.h"

int main(void)
{
  List_ptr list = create_list();
  add_to_end(list, 5);
  add_to_end(list, 6);
  add_to_start(list, 3);
  add_to_start(list, 2);
  insert_at(list, 4, 2);
  add_unique(list, 8);

  display(list);
  return 0;
}
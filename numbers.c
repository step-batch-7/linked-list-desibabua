#include <stdio.h>
#include "list.h"

int main(void)
{
  List_ptr list = create_list();
  add_to_end(list, 5);
  add_to_end(list, 6);
  add_to_end(list, 4);
  add_to_end(list, 3);

  display(list);
  return 0;
}
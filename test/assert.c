#include <stdio.h> 
#include "assert.h"

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
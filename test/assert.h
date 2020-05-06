#ifndef __ASSERT_H_
#define __ASSERT_H_

#define print_empty_line printf("\n")

void assert_num(int num1,int num2, char *message);;
void assert_is_eq_ptr(void *ptr1,void *ptr2, char *message);
void assert_is_not_eq_ptr(void *ptr1,void *ptr2, char *message);
void describe(char *function_name);
void it(char *testing_message);

#endif
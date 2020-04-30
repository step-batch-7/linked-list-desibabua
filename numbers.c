#include <stdio.h>
#include "list.h"

#define print(string) printf("%s\n",string)
#define print_empty_line printf("\n")

void print_main_menu(void)
{
  print("(a) add a number to the end of the list");
  print("(b) add a number to the start of the list");
  print("(c) insert a number at a given position in the list");
  print("(d) add a unique item on the list at the end(if it already exists, do not insert)");
  print("(e) remove a number from the beginning of the list");
  print("(f) remove a number from the end of the list");
  print("(g) remove a number from a given position in the list");
  print("(h) remove first occurrence of a number");
  print("(i) remove all occurrences of a number");
  print("(j) clear the whole list");
  print("(k) check if a number exists in the list");
  print("(l) display the list of numbers");
  print("(m) exit");
}

void ask_instruction(char *instruction)
{
  char temp;
  print_empty_line;
  print("Please enter the alphabet of the operation you would like to perform");
  scanf("%c", instruction);
  scanf("%c", &temp); //for clearing the buffer value of "\n"
}

void ask_number(char *question,int *number){
  char temp;
  print(question);
  scanf("%d", number);
  scanf("%c", &temp);
}

void perform_instruction(List_ptr list,char instruction)
{
  int number_1;
  int number_2;
  switch (instruction)
  {
  case 'a':
    ask_number("\nEnter number :", &number_1);
    add_to_end(list, number_1);
    break;

  case 'b':
    ask_number("\nEnter number :", &number_1);
    add_to_start(list, number_1);
    break;

  case 'c':
    ask_number("\nEnter number :", &number_1);
    ask_number("\nEnter position :", &number_2);
    insert_at(list, number_1, number_2);
    break;

  case 'd':
    ask_number("\nEnter number :", &number_1);
    add_unique(list, number_1);
    break;

  case 'e':
    remove_from_start(list);
    break;
    
  case 'l':
    print_empty_line;
    display(list);
    break;
  }
}

int main(void)
{
  char instruction;
  List_ptr list = create_list();
  
  do
  {
    print_main_menu();
    ask_instruction(&instruction);
    perform_instruction(list, instruction);
  } while (instruction != 'm');

  return 0;
}
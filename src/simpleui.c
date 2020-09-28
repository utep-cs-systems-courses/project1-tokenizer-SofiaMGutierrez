#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main(){
  List *list = init_history();
  printf("$ ");
  char user_input[100];
  fgets(user_input,100,stdin);
  printf("%s\n",user_input);
  add_history(list,user_input);
  char **tokens = tokenize(user_input);
  print_tokens(tokens);
  
  printf("Select menu option:\n");
  printf("1. Tokenize another string\n");
  printf("2. Print history\n");
  printf("3. Exit\n");
  char menu_choice;
  scanf("%d",&menu_choice);
  while(menu_choice != 3){
    if(menu_choice == 1){
      printf("$ ");
      char str[100];
      scanf(" %[^\n]",&str);
      printf("%s\n",str);
      add_history(list,str);
      char **tokens = tokenize(str);
      print_tokens(tokens);
    }
    if(menu_choice == 2){
      print_history(list);
    }
    if(menu_choice == 3){
      exit(0);
    }
    printf("Select menu option:\n");
    scanf("%d",&menu_choice);
  }
}

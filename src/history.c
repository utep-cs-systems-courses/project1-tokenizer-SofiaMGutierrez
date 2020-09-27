#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List *init_history(){
  List *history_list = malloc(sizeof(List));
  history_list->root = malloc(sizeof(Item));
  return history_list;
}

void add_history(List *list, char *str){
  Item *t = list->root; // temp value
  int count = 0;
  // Reaches last node
  while(t->next != NULL){
    count++;
    t = t->next;
  }
  t->str = str;
}

char *get_history(List *list, int id){
}

void print_history(List *list){
  Item *t = list->root;
  while(t->next != NULL){
    printf("str: %s\n", t->str);
    t = t->next;
  }
}

void free_history(List *list){
  free(list);
}

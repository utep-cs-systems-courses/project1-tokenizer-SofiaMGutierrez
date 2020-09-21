#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int main(){
  printf("$ ");
  char user_input[100];
  if(fgets(user_input,100,stdin)){
    printf("%s\n",user_input);
  }
}

int space_char(char c){
  if(c == '\t' && c == ' '){
    return 1;
  }
  else{
    return 0;
  }
}

int non_space_char(char c){
  return(!space_char(c) && c != '\0n');
}

char *word_start(char *str){
}

char *word_terminator(char *word){
}

int count_words(char *str){
}

char *copy_str(char *inStr, short len){
}

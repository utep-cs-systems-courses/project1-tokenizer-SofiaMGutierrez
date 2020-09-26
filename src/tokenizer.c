
#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int main(){
  printf("$ ");
  //char str[100];
  //fgets(str,100,stdin);
  char str[] = "I am cool";
  char **tokenized = tokenize(str);
  print_tokens(tokenized);
}

int space_char(char c){
  if(c == '\t' || c == ' '){
    return 1;
  }
  return 0;
}

int non_space_char(char c){
  if(c != '\t' || c != ' '){
    return 1;
  }
  return 0;
}

char *word_start(char *str){
  while(*str){
    if(non_space_char(*str)){
      return str;
    }
    str++;
  }
}

char *word_terminator(char *word){
  while(*word){
    if(space_char(*word)){
      return word;
    }
    word++;
  }
}

int count_words(char *str){
  int counter = 0;
  while(*str){
    if(space_char(*str)){
      counter++;
    }
    str++;
  }
  return counter = counter + 1;
}

// Created for copy_str function
int word_length(char *str){
  int counter = 0;
  while(*str){
    if(space_char(*str)){
      return counter;
    }
    counter++;
    str++;
  }
  return counter;
}

char *copy_str(char *inStr, short len){
  // Allocating memory for string
  // copiedStr will be dereferenced to access memory
  char *copiedStr = malloc(sizeof(char) * (len + 1));
  // Copying input string
  for(int i = 0; i < len; i++){
    copiedStr[i] = inStr[i];
  }
  // Appends a zero-terminator at the end
  copiedStr[len] = '\0';
  return copiedStr;
}

// Accepts a string of characters as input and returns an array of tokens
char **tokenize(char *str){
  char **tokens = malloc(sizeof(char)*(count_words(str)+1));
}

void print_tokens(char **tokens){
  printf("testing");
}

void free_tokens(char **tokens){
  free(tokens);
}

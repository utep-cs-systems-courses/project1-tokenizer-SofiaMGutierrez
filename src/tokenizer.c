
#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c){
  if((c == '\t' || c == ' ') && c != 0){
    return 1;
  }
  return 0;
}

int non_space_char(char c){
  if((c != '\t' && c != ' ')&& c != 0){
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
  return str;
}

char *word_terminator(char *word){
  while(*word){
    if(space_char(*word)){
      return word;
    }
    word++;
  }
  return word;
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
  int i;
  for(i = 0; i < len; i++){
    copiedStr[i] = inStr[i];
  }
  // Appends a zero-terminator at the end
  copiedStr[i] = 0;
  return copiedStr;
}

// Accepts a string of characters as input and returns an array of tokens
char **tokenize(char *str){
  char *pStr = str; // Points to string
  char **tokens = malloc(sizeof(char) * ((count_words(str))+1));
  int i;
  for(i = 0; i < (count_words(str)); i++){
    pStr = word_start(pStr);
    tokens[i] = copy_str(pStr, word_length(pStr));
    pStr = word_terminator(pStr);
  }
  tokens[i] = 0;
  return tokens;
}

void print_tokens(char **tokens){
  int i = 0;
  while(*tokens){
    printf("tokens[%d] = %s\n", i, *tokens);
    i++;
    tokens++;
  }
}

void free_tokens(char **tokens){
  free(tokens);
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct ListNode{
  char value[256];
  struct ListNode *next;
} ListNode;

void push(ListNode **start,char *data){
  ListNode *newNode;
  newNode=(ListNode*)malloc(sizeof(ListNode));
  newNode->next=NULL;
  strcpy(newNode->value, data);
  newNode->next=*start;
  *start=newNode;
}

char* pop(ListNode **start){
  if(*start==NULL){
    return NULL;
  }
  ListNode *current=*start;
  *start=(*start)->next;
  return current->value;
}

int main(){
  ListNode *stack=NULL;
  int n=0;
  char buffer[100];
    char *token;
    fgets(buffer, 100, stdin);
    if(buffer[strlen(buffer) - 1] == '\n'){
        buffer[strlen(buffer) - 1] = '\0';
    }
    token = strtok(buffer, " ");
    while (token != NULL)
    {   
        push(&stack,token);
        token = strtok(NULL, " ");
    }
  int count=0;
  scanf("%d",&n);
  while(count<n){
    if(stack==NULL){
      printf("None ");
    }
    else{
      printf("%s ",pop(&stack));
    }
    count++;
  }
}
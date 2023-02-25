#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPR_SIZE 100

char stack[MAX_EXPR_SIZE];
int top = -1;

void push(char c) {
  stack[++top] = c;
}

char pop() {
  return stack[top--];
}

int priority(char c) {
  if (c == '^')
    return 3;
  else if (c == '*' || c == '/')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
  else
    return -1;
}

char *infixToPostfix(char *infix, int mode) {
  int i, j;
  char c;
  char *postfix;
  postfix = infix;

  for (i = 0, j = 0; i < strlen(infix); i++) {
    c = infix[i];
    if (isalnum(c))
      postfix[j++] = c;
    else if (c == '(')
      push(c);
    else if (c == ')') {
      while (stack[top] != '(')
        postfix[j++] = pop();
      pop();
    } else {
      if(mode == 1){
      while (priority(stack[top]) > priority(c))
        postfix[j++] = pop();}
      else if (mode == 2){
        while (priority(stack[top]) >= priority(c))
        postfix[j++] = pop();
        }
      push(c);
      }
      
    }
  

  while (top != -1)
    postfix[j++] = pop();
  postfix[j] = '\0';
  return postfix;
}

void reverse(char *exp){

    int size = strlen(exp);
    int j = size, i=0;
    char temp[size];

    temp[j--]='\0';
    while(exp[i]!='\0')
    {
        temp[j] = exp[i];
        j--;
        i++;
    }
    strcpy(exp,temp);
}
void brackets(char* exp){
    int i = 0;
    while(exp[i]!='\0')
    {
        if(exp[i]=='(')
            exp[i]=')';
        else if(exp[i]==')')
            exp[i]='(';
        i++;
    }
}

void InfixtoPrefix(char *exp){

    int size = strlen(exp);

    // reverse string
    reverse(exp);
    //change brackets
    brackets(exp);
  
    //get postfix
    infixToPostfix(exp, 1);
  
    // reverse string again
    reverse(exp);

}

int main(){
  char infix[MAX_EXPR_SIZE];
  char infix2[MAX_EXPR_SIZE];
  char* postfix;

  
  scanf("%s", infix);

  strcpy(infix2, infix);

  InfixtoPrefix(infix2);
  printf("%s\n", infix2);
  printf("%s", infixToPostfix(infix, 2));
}
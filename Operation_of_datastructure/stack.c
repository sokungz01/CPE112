#include<stdio.h>
#include<stdlib.h>

struct node{
    int value;
    struct node *next;
};

void push(struct node **top, int value);
int pop(struct node **top);
int peek(struct node **top);

void push(struct node **top , int value){
    struct node *newNode = NULL;
    newNode = (struct node*)calloc(1,sizeof(struct node));
    newNode->value = value;
    newNode->next = NULL;
    if(*top == NULL){
        *top = newNode;
    }
    else{
        newNode->next = *top;
        *top = newNode;
    }
}

int pop(struct node **top){
    struct node *removeNode = *top;
    if(removeNode == NULL){
        return -1;
    }
    *top = (*top)->next;
    free(removeNode);
    return 1;
}

int peek(struct node **top){
    return (*top)->value;
}

int main(){
    struct node *stack = NULL;
    int value = 0;
    while(scanf("%d",&value) == 1){
        push(&stack,value);
    }
    printf("%d",peek(&stack));
    pop(&stack);
    printf("%d",peek(&stack));
    return 0;
}
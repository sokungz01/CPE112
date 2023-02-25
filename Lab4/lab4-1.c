#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX, FRONT, REAR, BUFFER_MAX = 1000;

char **QUEUE;

void initQueue(int size){
     MAX = size;
    FRONT = -1;
    REAR = -1;
    
    //Sting Array Allocation 
    QUEUE = (char**)malloc(sizeof(char*)*MAX);
    for(int i = 0; i<MAX;i++){
        QUEUE[i] = (char*)malloc(sizeof(char)*MAX);
    }
    //printf("==Initiated Queue!==\n");
}

int isFull(){
    if ((FRONT == REAR + 1) || (FRONT == 0 && REAR == MAX - 1)){
        return 1;
    } 
    return 0;
}

int isEmpty(){
    if(FRONT == -1){
        return 1;
    }
    return 0;
}

int enqueue(char* val){
    if(isFull()){
        printf("FULLqueue\n");
        return 0;
    }
    else{
        if(FRONT == -1){
            FRONT = 0;
            }
            REAR = (REAR+1) % MAX;
            strcpy(QUEUE[REAR],val);
            return 1;
    }
}


char* dequeue(){
    char* removedStr;
    if(isEmpty()){
        printf("None ");
        return NULL;
    }
    else{
        removedStr = QUEUE[FRONT];
        if(FRONT == REAR){
        FRONT = -1;
        REAR = -1;
        }
        else{
        FRONT = (FRONT+1)%MAX;
        }
        printf("%s ",removedStr);
        return removedStr;
    }
}


void display(char *str){
    char *ptr = str;
    while(*ptr != '\0'){
        if(*ptr == '\n'){
        printf("[newline!] ");
        }
        else{
        printf("%c ",*ptr);
        }
        ptr++;
    }
    printf("\n");
}

void displayQueue(){
    for(int i =FRONT; i<=REAR; i++){
        printf("%s ",QUEUE[i]);
    }
    printf("\n");
}

void removenewline(char *str){
    int lastIdx= strlen(str)-1;
    if(str[lastIdx] == '\n'){
        str[lastIdx] = '\0';
    }
}

//get string input 
void numinput(int* num){
    char* buffer;
    int length;
    buffer = (char*)malloc(BUFFER_MAX);
    fgets(buffer,BUFFER_MAX,stdin);
    //remove \n 
    length = strlen(buffer);
    removenewline(buffer);
    sscanf(buffer,"%d",num);
}

void strinput(char *str){
  char* buffer;
  int length;
  buffer = (char*)malloc(BUFFER_MAX);
  fgets(buffer,BUFFER_MAX,stdin);
  removenewline(buffer);
  strcpy(str,buffer);
  free(buffer);
}


int main(void) {
    char *inputStr = (char*)malloc(sizeof(char)*BUFFER_MAX);
    char *token;
    int queueSize,numDeq, r=0;
    
    numinput(&queueSize);
    initQueue(queueSize);
    while(r<2){
        strinput(inputStr);
        token = strtok(inputStr, " ");
        while(token!=NULL &&  enqueue(token)){
          token = strtok(NULL, " ");
        }
        numinput(&numDeq);
        for(int i=0; i<numDeq; i++){
          dequeue();
        }
        printf("\n");
        r++;
  }
  return 0;
}
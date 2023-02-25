```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct QNode {//make queue node
  char data[32];
  struct QNode *next;
};
struct Queue {//make front and rear node for Queue
  struct QNode *front, *rear;
};

struct QNode *newNode(char* k) {
  struct QNode *temp = (struct QNode *)malloc(sizeof(struct QNode));
  strcpy(temp->data, k);
  temp->next = NULL;
  return temp;
}

struct Queue *createQueue() {
  struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
  q->front = q->rear = NULL;
  //printf("Queue Created\n");
  return q;
}

// The function to add a data k to q
void enQueue(struct Queue *q, char* k) {
  struct QNode *temp = newNode(k);
  //printf("< %s >",temp->data);
  if (q->rear == NULL) {
    q->front = q->rear = temp;
    //printf("%s",&temp->data);
    return;
  }

  // Add the new node at the end of queue and change rear
  q->rear->next = temp;
  q->rear = temp;
  //printf("<%s>",&temp->data);
}

// Function to remove a data from given queue q
void deQueue(struct Queue *q) {
  // If queue is empty, return NULL.
  /*if (q->front == NULL)
    return;*/
  // Store previous front and move front one node ahead

  // If front becomes NULL, then change rear also as NULL
  if (q->front == NULL){
    q->rear = NULL;
    free(q);
    return;
  }else if (q->front->next==NULL){
    printf("%s ", q->front->data);//print the last node
  }
  else if(1){
    struct QNode *temp = q->front;
    q->front = q->front->next;
    printf("%s ", temp->data);
    free(temp);
    }
}

int main() {
  char num[1000];
  int count = 0, deq, empty = 0;
  fgets(num, 1000, stdin);
   if (num[strlen(num) - 1] == '\n') {
    num[strlen(num) - 1] = '\0';
  }
  char *input = strtok(num," ");
  struct Queue *q = createQueue();
  while (input != NULL) {
    enQueue(q,input);
    //printf("EnQueue Completed\n");
    count++;
    //printf("%d\n", count);
    input = strtok(NULL, " ");
  }
  scanf("%d", &deq);
  while(deq > count) {
    empty++;
    deq--;
  }
  //printf("%d \n",deq);
  while (deq != -1 && deq!=NULL) {
    deQueue(q);
     deq--;
  }
  if(empty!=0){
    for(empty;empty>0;empty--){
      printf("None ");
    }
  }
  return 0;
}
```
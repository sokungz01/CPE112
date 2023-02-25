#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int MAX_PRIORITY = 0;
struct node
{
    char data[32];
    int priority;
    struct node *next;
};

struct queue
{
    struct node *front;
    struct node *rear;
};

void enqueue(struct queue *q, char *data, int priority)
{   
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    strcpy(temp->data, data);
    temp->priority = priority;
    temp->next = NULL;

    /* If queue is empty || newData-Priority > priority on front node */
    if (q->front == NULL || priority > q->front->priority)
    {
        /* set front node is a new data */
        temp->next = q->front;
        q->front = temp;
        MAX_PRIORITY = priority;
    }
    else
    {
        struct node *current = q->front;
        if(MAX_PRIORITY < priority){
            MAX_PRIORITY = priority;
        }
        /* Traverse in condition new priority is less equal than node that in queue */
        while (current->next != NULL && current->next->priority >= priority)
        {
            current = current->next;
        }
        temp->next = current->next;
        current->next = temp;
        if (temp->next == NULL)
        {
            q->rear = temp;
        }
    }
}

char *dequeue(struct queue *q)
{
    if (q->front == NULL)
    {
        return NULL;
    }
    struct node *temp = q->front;
    char *data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
    {
        q->rear = NULL;
    }
    return data;
}

int main()
{   
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->front = NULL;
    q->rear = NULL;
;
    char buffer[100000];
    char *token;
    char data[32];
    int priority = 0;
    fgets(buffer,100000,stdin);
    if(buffer[strlen(buffer)-1] == '\n'){
        buffer[strlen(buffer)-1] = '\0';
    }
    token = strtok(buffer, " ");
    while (token != NULL)
    {
        sscanf(token,"%s",data);
        token = strtok(NULL, " ");
        sscanf(token,"%d",&priority);
        token = strtok(NULL, " ");
        if(priority == -1){
            priority = MAX_PRIORITY +1;
        }
        enqueue(q,data,priority);
    }
    int dequeue_times = 0;
    scanf("%d",&dequeue_times);
    for(int i = 0 ; i < dequeue_times ; i++ ){
        char *temp_data = dequeue(q);
        if(temp_data == NULL){
            printf("None");
            break;
        }
        printf("%s ",temp_data);
    }
    return 0;
}
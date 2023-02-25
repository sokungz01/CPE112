#include<stdio.h>
#include<stdlib.h>
struct node {
    int value;
    struct node *next;
};

struct node *traverse(struct node **head);
void createList(struct node **head);
void displayList(struct node **head);
void insertBegin(struct node **head);
void insertNode(struct node **head);
void deleteNode(struct node **head);
void deleteBegin(struct node **head);

struct node *traverse(struct node **head){
    if(*head == NULL){
        return NULL;
    }
    struct node *temp = NULL;
    temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    return temp;
}

void createList(struct node **head){
    struct node *newNode = NULL;
    struct node *temp = NULL;
    *head = NULL; //need to initialize before use
    int value = 0;
    while(scanf("%d",&value) == 1){
        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->value = value;
        newNode->next = NULL;
        if(*head == NULL)
            *head = newNode;
        else
        {   
            temp = traverse(head);
            temp->next = newNode;
        }
    }
}

void displayList(struct node **head){
    struct node *temp = NULL;
    temp = *head;
    while(temp != NULL){
        printf("%d ",temp->value);
        temp = temp->next;
    }
}

void insertBegin(struct node **head)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node)); // STEP 1-3
    int value;
    printf("Insert value at begin :");
    scanf("%d", &value);
    newNode->value = value;  // STEP 4
    newNode->next = (struct node*)*head; // STEP 5
    *head = newNode;       // STEP 6
}

void insertNode(struct node **head){
    struct node *temp = NULL;
    temp = traverse(head);
    if(temp == NULL){
        return;
    }
    struct node *newNode = NULL;
    int value = 0;
    scanf("%d",&value);
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->value = value;
    newNode->next = NULL;
    temp->next = newNode;
}

void deleteNode(struct node **head){
    struct node *Node = NULL;
    struct node *preNode = NULL;
    Node = *head;
    while(Node->next != NULL){
        preNode = Node;
        Node = Node->next;
    }
    preNode->next = NULL;
    free(Node);
}

void deleteBegin(struct node **head){
    struct node *ptr = *head;                 //Assign memory of first node into ptr pointer to node; 
    *head = (*head)->next;    //Assign address of second node into start pointer;
    free(ptr);                          //free memory of first node;
}

int main(){
    struct node *linkedlist;
    char buffer;
    createList(&linkedlist);
    displayList(&linkedlist);
    // scanf("%c",&buffer);
    // insertNode(&linkedlist);
    deleteNode(&linkedlist);
    displayList(&linkedlist);
    deleteBegin(&linkedlist);
    displayList(&linkedlist);
    return 0;
}
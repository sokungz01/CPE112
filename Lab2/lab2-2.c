#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

void createList(struct ListNode **start)
{
    int input;
    struct ListNode *newNode, *ptr;
    *start = NULL;
    while (scanf("%d", &input) == 1)
    {
        newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->val = input;
        newNode->next = NULL;
        if (*start == NULL)
            *start = newNode;
        else
            ptr->next = (struct ListNode *)newNode;
        ptr = newNode;
    }
}

// function used to reverse a linked list
struct ListNode *reverseList(struct ListNode **start)
{
    struct ListNode *previous = NULL , *next = NULL , *current = *start ;
    while (current != NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    return previous;
}

// function used to reverse a linked list from position m to n
void reverseBetween(struct ListNode **start)
{
    int startPoint, endPoint;
    char dummy[4];
    scanf("%s", dummy);
    scanf("%d %d", &startPoint, &endPoint);
    if (startPoint == endPoint)
        return;
    struct ListNode *revStart = NULL, *revStart_previous = NULL;
    struct ListNode *revEnd = NULL, *revEnd_next = NULL;
    struct ListNode *current = *start;
    int i = 1;
    while (current != NULL && i <= endPoint)
    {
        if (i < startPoint)
            revStart_previous = current;
        if (i == startPoint)
            revStart = current;
        if (i == endPoint)
        {
            revEnd = current;
            revEnd_next = current->next;
        }
        current = current->next;
        i++;
    }
    revEnd->next = NULL;
    revEnd = reverseList(&revStart);
    if (revStart_previous)
        revStart_previous->next = revEnd;
    else
        *start = revEnd;
    revStart->next = revEnd_next;
}

void printList(struct ListNode **start)
{
    struct ListNode *ptr = *start;
    while (ptr != NULL)
    {
        printf("%d ", ptr->val);
        ptr = ptr->next;
    }
}

int main()
{
    struct ListNode *list;
    createList(&list);
    reverseBetween(&list);
    printList(&list);
}
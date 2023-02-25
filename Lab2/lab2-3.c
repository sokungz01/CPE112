#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int value;
    struct node *next;
    struct node *prev;
} node;

// Get A Value From The User And Insert to Linked list until user type end
void get_value(node **head)
{
    int value;
    node *new_node = NULL;
    node *temp = NULL;

    while( scanf("%d",&value) == 1)
    {
        new_node = (node *)malloc(sizeof(node));
        new_node->value = value;
        new_node->next = NULL;
        new_node->prev = NULL;
        if (*head == NULL)
        {
            *head = new_node;
        }
        else
        {
            temp = *head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->prev = temp;
        }
    }
}

void print_list(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

// check palindrome
int check_palindrome(node *head)
{
    node *start = head;
    node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    while (start != tail)
    {
        if (start->value != tail->value)
        {
            return 0;
        }
        start = start->next;
        tail = tail->prev;
    }
    return 1;
}
// free the linked list
void free_list(node **head)
{
    // free the linked list
    node *temp = *head;
    node *temp2 = NULL;
    while (temp != NULL)
    {
        temp2 = temp->next;
        free(temp);
        temp = temp2;
    }
    *head = NULL;
}
void copy_drop(node *head ,node ** newhead , int index){
    node *temp = head;
    node *new_node = NULL;
    int i = 0;
    while (temp != NULL)
    {
        if (i != index)
        {
            new_node = (node *)malloc(sizeof(node));
            new_node->value = temp->value;
            new_node->next = NULL;
            new_node->prev = NULL;
            if (*newhead == NULL)
            {
                *newhead = new_node;
            }
            else
            {
                node *temp2 = *newhead;
                while (temp2->next != NULL)
                {
                    temp2 = temp2->next;
                }
                temp2->next = new_node;
                new_node->prev = temp2;
            }
        }
        temp = temp->next;
        i++;
    }
}
int check_palindrome_by_delete(node *head)
{
    node *start = head;
    node *newhead = NULL;
    int index = 0;
    while (start != NULL)
    {
        // check if we can delete the start node
        copy_drop(head, &newhead, index);
        if (check_palindrome(newhead))
        {
            free_list(&newhead);
            return index;
        }
        free_list(&newhead);
        start = start->next;
        index++;
    }
    return -1;
}

int main()
{
    node *head = NULL;
    int index = 0;
    get_value(&head);
    if (check_palindrome(head))
    {
        printf("None");
    }
    else
    {
        index = check_palindrome_by_delete(head);
        if (index == -1)
        {
            printf("None");
        }
        else
        {
            printf("%d", index);
        }
    }
    return 0;
}
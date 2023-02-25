#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int value;
    struct node *next;
} node;

// Get A Value From The User And Insert to Linked list until user type end
void get_value(node **head)
{
    char input[10];
    int value;
    node *new_node = NULL;
    node *temp = NULL;

    while (1)
    {
        scanf("%s", input);
        if (strcmp(input, "END") == 0)
        {
            break;
        }
        value = atoi(input);
        new_node = (node *)malloc(sizeof(node));
        new_node->value = value;
        new_node->next = NULL;
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
        }
    }
}

void print_list(node *head)
{
    node *temp = head;
    if (temp == NULL)
    {
        printf("None\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d ", temp->value);
            temp = temp->next;
        }
        printf("\n");
    }
}

// drop node from linked list
void drop_node(node **head, node *target)
{
    node *temp = *head;
    if (temp == target)
    {
        *head = temp->next;
        free(temp);
    }
    else
    {
        while (temp->next != target)
        {
            temp = temp->next;
        }
        temp->next = target->next;
        free(target);
    }
}

// Distinct Value in Linked List
// 1 2 3 4 5 6 7 8 9 10 10 9 8 7 6 5 4 3 2 1 11
// 11
// if there is no distinct value, print None
void distinct(node **head)
{
    node *temp = *head;
    node *temp2 = NULL;
    node *temp3 = NULL;
    int chk = 0;
    // no prev pointer
    while (temp != NULL)
    {
        chk = 0;
        temp2 = temp->next;
        while (temp2 != NULL)
        {
            if (temp->value == temp2->value)
            {
                chk = 1;
                temp3 = temp2;
                temp2 = temp2->next;
                drop_node(head, temp3);
            }
            else
            {
                temp2 = temp2->next;
            }
        }
        if(chk == 1)
        {
            temp3 = temp;
            temp = temp->next;
            drop_node(head, temp3);
        }
        else
        {
            temp = temp->next;
        }
    }
}

int main()
{
    node *head = NULL;
    get_value(&head);
    distinct(&head);
    print_list(head);
    return 0;
}

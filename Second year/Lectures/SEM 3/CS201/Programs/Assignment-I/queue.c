#include <stdio.h>
#include <stdlib.h>
#define take(n) scanf("%d", &n);
#define rep(i, a, b) for (int i = a; i < b; i++)

typedef struct nod{
    int data;
    struct nod *next;
} node;

void insert_q(node **head, node *current)
{
    if (*head == NULL){
        *head = current;
        return;
    }
    node *temp = *head, *prev = NULL;
    while (temp != NULL){
        prev = temp;
        temp = temp->next;
    }
    prev->next = current;
}

void takeinput(node **head)
{
    printf("Enter the value of the element : ");
    int value;
    take(value);
    node *current = (node *)malloc(sizeof(node));
    current->data = value;
    current->next = NULL;
    insert_q(head, current);
}

node *delete_q(node **head)
{
    if (*head == NULL) return NULL;
    else{
        node *temp = *head;
        *head = (*head)->next;
        temp->next = NULL;
        return temp;
    }
}

void printlinkedlist(node *head)
{
    if (head == NULL) printf("Linkedlist is empty\n");
    else
    {
        printf("Current linkedlist is: ");
        node *temp = head;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void delete_linkedlist(node **head)
{
    node *temp = *head;
    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main()
{
    node *queue;
    node *deleted;
    int choice;
    do
    {
        printf("Press 1 to input element inside queue\n");
        printf("Press 2 to delete the element from the queue\n");
        printf("Press 0 to exit\n");
        take(choice);
        switch (choice){
        case 1:
            takeinput(&queue);
            printlinkedlist(queue);
            break;
        case 2:
            deleted = delete_q(&queue);
            if (deleted != NULL){
                printf("value deleted is:%d\n", deleted->data);
                free(deleted);
            }
            printlinkedlist(queue);
        default:
            break;
        }

    } while (choice);
    delete_linkedlist(&queue);
    return 0;
}
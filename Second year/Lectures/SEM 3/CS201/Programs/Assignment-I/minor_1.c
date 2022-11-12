#include <stdio.h>
#include<stdlib.h>
#define take(n) scanf("%d", &n);
#define rep(i, a, b) for (int i = a; i < b; i++)
typedef struct nod
{
    int data;
    struct nod *next;
} node;

node *takeinput()
{
    printf("Enter the number of elements in the linkedlist\n");
    int n;
    take(n);
    node *temp, *head = NULL;
    rep(i, 0, n)
    {
        node *current = (node *)malloc(sizeof(node));
        int value;
        printf("Enter the value of element no %d : ", i + 1);
        take(value);
        current->data = value;
        current->next = NULL;
        if (i == 0)
            head = current;
        else
            temp->next = current;
        temp = current;
    }
    return head;
}
void printlinkedlist(node *head)
{

    node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void action(node **head, int k)
{
    if (k == 0) return;
    node *temp = *head;
    int count = 1;
    while (count < (k + 1) && temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    if (temp == NULL)
        return;
    node *target = temp;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = *head;
    *head = target->next;
    target->next = NULL;
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
    node *node1 = takeinput();
    action(&node1,3);
    printlinkedlist(node1);
    return 0;
}
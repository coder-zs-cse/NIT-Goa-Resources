#include <stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
 
struct Node* addToEmpty(struct Node* head, int data)
{
    if (head != NULL)
        return head;
 
    struct Node* temp= (struct Node*)malloc(sizeof(struct Node));
 
    temp->data = data;
    head = temp;
 
    head->next = head;
 
    return head;
}
 
struct Node* addBegin(struct Node* head, int data)
{
    if (head == NULL)
        return addToEmpty(head, data);
 
    struct Node* temp
        = (struct Node*)malloc(sizeof(struct Node));
 
    temp->data = data;
    temp->next = head->next;
    head->next = temp;
 
    return head;
}
 
void traverse(struct Node* head)
{
    struct Node* p;
 
    if (head == NULL) {
        printf("LIST is empty\n");
        return;
    }
 
    p = head;
 
    do {
        printf("%d ",p->data);
        p = p->next;
 
    } while (p != head);
}

struct Node* exchangeNodes(struct Node* head)
{

    if (head->next->next == head) {
        head = head->next;
        return head;
    }
 
    struct Node* p = head;
    while (p->next->next != head)
        p = p->next;
 
    p->next->next = head->next;
    head->next = p->next;
    p->next = head;
    head = head->next;
 
    return head;
}
 
int main()
{
    int i;
    struct Node* head = NULL;
    head = addToEmpty(head, 6);
 
    for (i = 5; i > 0; i--)
        head = addBegin(head, i);
    printf("CLIST before: ");
    traverse(head);
    printf("\n");
 
    printf("CLIST after: ");
    head = exchangeNodes(head);
    traverse(head);
 
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

/* -------- SINGLY LINKED LIST -------- */
struct SNode
{
    int data;
    struct SNode *next;
};

/* Traverse Singly Linked List */
void traverseSingly(struct SNode *head)
{
    struct SNode *temp = head;
    printf("\nSingly Linked List Traversal:\n");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* -------- DOUBLY LINKED LIST -------- */
struct DNode
{
    int data;
    struct DNode *prev;
    struct DNode *next;
};

/* Traverse Doubly Linked List */
void traverseDoubly(struct DNode *head)
{
    struct DNode *temp = head;
    printf("\nDoubly Linked List Traversal:\n");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* -------- MAIN FUNCTION -------- */
int main()
{
    /* Singly Linked List Nodes */
    struct SNode *s1, *s2, *s3;

    s1 = (struct SNode *)malloc(sizeof(struct SNode));
    s2 = (struct SNode *)malloc(sizeof(struct SNode));
    s3 = (struct SNode *)malloc(sizeof(struct SNode));

    s1->data = 10;
    s2->data = 20;
    s3->data = 30;

    s1->next = s2;
    s2->next = s3;
    s3->next = NULL;

    traverseSingly(s1);

    /* Doubly Linked List Nodes */
    struct DNode *d1, *d2, *d3;

    d1 = (struct DNode *)malloc(sizeof(struct DNode));
    d2 = (struct DNode *)malloc(sizeof(struct DNode));
    d3 = (struct DNode *)malloc(sizeof(struct DNode));

    d1->data = 100;
    d2->data = 200;
    d3->data = 300;

    d1->prev = NULL;
    d1->next = d2;
    d2->prev = d1;
    d2->next = d3;
    d3->prev = d2;
    d3->next = NULL;

    traverseDoubly(d1);

    return 0;
}
Singly Linked List Traversal:
10 -> 20 -> 30 -> NULL

Doubly Linked List Traversal:
100 <-> 200 <-> 300 <-> NULL


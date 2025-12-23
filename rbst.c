#include <stdio.h>
#include <stdlib.h>

/* -------- Binary Tree -------- */
struct Tree {
    int data;
    struct Tree *left, *right;
};

struct Tree* newTree(int x) {
    struct Tree* t = (struct Tree*)malloc(sizeof(struct Tree));
    t->data = x; t->left = t->right = NULL;
    return t;
}

void inorder(struct Tree* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

/* -------- Singly Linked List -------- */
struct SNode {
    int data;
    struct SNode* next;
};

struct SNode* newSNode(int x) {
    struct SNode* n = (struct SNode*)malloc(sizeof(struct SNode));
    n->data = x; n->next = NULL;
    return n;
}

void displaySLL(struct SNode* head) {
    if (head == NULL) return;
    printf("%d -> ", head->data);
    displaySLL(head->next);
}

/* -------- Doubly Linked List -------- */
struct DNode {
    int data;
    struct DNode *prev, *next;
};

struct DNode* newDNode(int x) {
    struct DNode* n = (struct DNode*)malloc(sizeof(struct DNode));
    n->data = x; n->prev = n->next = NULL;
    return n;
}

void displayDLL(struct DNode* head) {
    if (head == NULL) return;
    printf("%d <-> ", head->data);
    displayDLL(head->next);
}

/* -------- Main Function -------- */
int main() {

    /* Tree */
    struct Tree* root = newTree(1);
    root->left = newTree(2);
    root->right = newTree(3);

    printf("Tree Inorder: ");
    inorder(root);
    printf("\n");

    /* Singly Linked List */
    struct SNode* s = newSNode(10);
    s->next = newSNode(20);
    s->next->next = newSNode(30);

    printf("Singly List: ");
    displaySLL(s);
    printf("NULL\n");

    /* Doubly Linked List */
    struct DNode* d1 = newDNode(5);
    struct DNode* d2 = newDNode(6);
    struct DNode* d3 = newDNode(7);
    d1->next = d2; d2->prev = d1;
    d2->next = d3; d3->prev = d2;

    printf("Doubly List: ");
    displayDLL(d1);
    printf("NULL\n");

    return 0;
}
Tree Inorder: 2 1 3 
Singly List: 10 -> 20 -> 30 -> NULL
Doubly List: 5 <-> 6 <-> 7 <-> NULL

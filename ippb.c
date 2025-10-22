#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

// Node structure
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Queue for BFS
typedef struct Queue {
    Node* data[MAX];
    int front, rear;
} Queue;

// Queue operations
void enqueue(Queue* q, Node* node) {
    q->data[q->rear++] = node;
}

Node* dequeue(Queue* q) {
    return q->data[q->front++];
}

bool isEmpty(Queue* q) {
    return q->front == q->rear;
}

// Create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Traversals
void inOrder(Node* root) {
    if (root) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void preOrder(Node* root) {
    if (root) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node* root) {
    if (root) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

// Breadth-First Search
void bfs(Node* root) {
    Queue q = { .front = 0, .rear = 0 };
    enqueue(&q, root);
    while (!isEmpty(&q)) {
        Node* current = dequeue(&q);
        printf("%d ", current->data);
        if (current->left) enqueue(&q, current->left);
        if (current->right) enqueue(&q, current->right);
    }
}

// AVL Tree utilities
int height(Node* node) {
    if (!node) return 0;
    int lh = height(node->left);
    int rh = height(node->right);
    return (lh > rh ? lh : rh) + 1;
}

int getBalance(Node* node) {
    if (!node) return 0;
    return height(node->left) - height(node->right);
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    return y;
}

// Insert into AVL Tree
Node* insertAVL(Node* node, int key) {
    if (!node) return createNode(key);
    if (key < node->data)
        node->left = insertAVL(node->left, key);
    else if (key > node->data)
        node->right = insertAVL(node->right, key);
    else return node;

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->data)
        return rightRotate(node);
    if (balance < -1 && key > node->right->data)
        return leftRotate(node);
    if (balance > 1 && key > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Main function
int main() {
    Node* root = NULL;
    int values[] = {30, 20, 40, 10, 25, 35, 50};
    int n = sizeof(values)/sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        root = insertAVL(root, values[i]);
    }

    printf("In-Order Traversal: ");
    inOrder(root);
    printf("\n");

    printf("Pre-Order Traversal: ");
    preOrder(root);
    printf("\n");

    printf("Post-Order Traversal: ");
    postOrder(root);
    printf("\n");

    printf("Breadth-First Search (BFS): ");
    bfs(root);
    printf("\n");

    return 0;
}





output:  




In-Order Traversal: 10 20 25 30 35 40 50 
Pre-Order Traversal: 30 20 10 25 40 35 50 
Post-Order Traversal: 10 25 20 35 50 40 30 
Breadth-First Search (BFS): 30 20 40 10 25 35 50 

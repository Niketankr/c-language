#include <stdio.h>
#include <stdlib.h>

// Binary tree node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Apply bitwise operation on subtree
void bitwiseSubtree(struct Node* root, int value, char op) {
    if (root == NULL)
        return;

    switch (op) {
        case '&':   // AND
            root->data = root->data & value;
            break;
        case '|':   // OR
            root->data = root->data | value;
            break;
        case '^':   // XOR
            root->data = root->data ^ value;
            break;
        case '~':   // NOT (value ignored)
            root->data = ~root->data;
            break;
        case 'A':   // NAND
            root->data = ~(root->data & value);
            break;
        case 'O':   // NOR
            root->data = ~(root->data | value);
            break;
        default:
            printf("Invalid operation\n");
            return;
    }

    bitwiseSubtree(root->left, value, op);
    bitwiseSubtree(root->right, value, op);
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    // Create binary tree
    struct Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(15);
    root->left->left = newNode(3);
    root->left->right = newNode(7);

    printf("Before operation:\n");
    inorder(root);

    // Apply bitwise operation on left subtree
    bitwiseSubtree(root->left, 2, 'A'); // NAND with 2

    printf("\n\nAfter NAND with 2 on left subtree:\n");
    inorder(root);

    return 0;
}
output:

Before operation:
3 5 7 10 15 

After NAND with 2 on left subtree:
-3 -1 -3 10 15

//second

#include <stdio.h>
#include <stdlib.h>

// Binary tree node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Apply bitwise operation on subtree
void bitwiseSubtree(struct Node* root, int value, char op) {
    if (root == NULL)
        return;

    if (op == '&')
        root->data = root->data & value;
    else if (op == '|')
        root->data = root->data | value;
    else if (op == '^')
        root->data = root->data ^ value;

    bitwiseSubtree(root->left, value, op);
    bitwiseSubtree(root->right, value, op);
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    // Create tree
    struct Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(15);
    root->left->left = newNode(3);
    root->left->right = newNode(7);

    printf("Before bitwise operation:\n");
    inorder(root);

    // Apply bitwise XOR with 2 on left subtree
    bitwiseSubtree(root->left, 2, '^');

    printf("\n\nAfter XOR with 2 on left subtree:\n");
    inorder(root);

    return 0;
}
output:


Before bitwise operation:
3 5 7 10 15 

After XOR with 2 on left subtree:
1 7 5 10 15 

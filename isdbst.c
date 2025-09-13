#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};
struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct node* insertNode(struct node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }

    return root;
}
struct node* search(struct node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}
struct node* findMin(struct node* node) {
    struct node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}
struct node* deleteNode(struct node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
void inorderTraversal(struct node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct node* root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 70);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 60);
    insertNode(root, 80);

    printf("BST after insertions (in-order traversal): ");
    inorderTraversal(root);
    printf("\n\n");
    int searchKey = 40;
    if (search(root, searchKey) != NULL) {
        printf("Node with value %d found in the BST.\n\n", searchKey);
    } else {
        printf("Node with value %d not found in the BST.\n\n", searchKey);
    }
printf("Deleting 20 (leaf node)...\n");
    root = deleteNode(root, 20);
    printf("BST after deleting 20: ");
    inorderTraversal(root);
    printf("\n\n");

    printf("Deleting 70 (node with two children)...\n");
    root = deleteNode(root, 70);
    printf("BST after deleting 70: ");
    inorderTraversal(root);
    printf("\n\n");
    printf("Deleting 50 (root node)...\n");
    root = deleteNode(root, 50);
    printf("BST after deleting 50: ");
    inorderTraversal(root);
    printf("\n\n");

    return 0;
}

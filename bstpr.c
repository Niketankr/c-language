#include <stdio.h>
#include <stdlib.h>

#define MAX 100


struct Node {
    int key;
    struct Node *left, *right;
};


struct Node* createNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}


struct Node* insert(struct Node* root, int key) {
    if (root == NULL)
        return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}


int A[MAX], B[MAX], C[MAX];
int aCount = 0, bCount = 0, cCount = 0;


void storeSubtree(struct Node* root, int arr[], int *count) {
    if (root == NULL) return;
    arr[(*count)++] = root->key;
    storeSubtree(root->left, arr, count);
    storeSubtree(root->right, arr, count);
}


void searchAndClassify(struct Node* root, int key) {
    struct Node* current = root;

    while (current != NULL) {
        B[bCount++] = current->key;  

        if (key < current->key) {
           
            storeSubtree(current->right, C, &cCount);
            current = current->left;
        }
        else if (key > current->key) {
            
            storeSubtree(current->left, A, &aCount);
            current = current->right;
        }
        else {
            break; 
        }
    }
}


void printSet(char name[], int arr[], int count) {
    printf("%s = { ", name);
    for (int i = 0; i < count; i++)
        printf("%d ", arr[i]);
    printf("}\n");
}

int main() {
    struct Node* root = NULL;

    /*
        Counterexample BST:

                15
               /  \
              6    18
               \
                12
               /
              9
    */

    root = insert(root, 15);
    root = insert(root, 6);
    root = insert(root, 18);
    root = insert(root, 12);
    root = insert(root, 9);

    int searchKey = 9;

    searchAndClassify(root, searchKey);

    printf("Search Key: %d\n\n", searchKey);

    printSet("A (Left of path)", A, aCount);
    printSet("B (Search path)", B, bCount);
    printSet("C (Right of path)", C, cCount);

    return 0;
}


output:

Search Key: 9

A (Left of path) = { }
B (Search path) = { 15 6 12 9 }
C (Right of path) = { 18 }


=== Code Execution Successful ===

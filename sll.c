#include <stdio.h>
#include <stdlib.h>

int main() {
    // 1. Single-Dimensional Array
    int arr[5] = {1, 2, 3, 4, 5};
    printf("Single-Dimensional Array:\n");
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    // 2. Multidimensional Array (2D)
    int matrix[2][3] = {
        {10, 20, 30},
        {40, 50, 60}
    };
    printf("\nMultidimensional Array (2D):\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("matrix[%d][%d] = %d\n", i, j, matrix[i][j]);
        }
    }

    // 3. Dynamic Size Array
    int size;
    printf("\nEnter size of dynamic array: ");
    scanf("%d", &size);

    int *dynArr = (int *)malloc(size * sizeof(int));
    if (dynArr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &dynArr[i]);
    }

    printf("Dynamic Array:\n");
    for (int i = 0; i < size; i++) {
        printf("dynArr[%d] = %d\n", i, dynArr[i]);
    }

    free(dynArr); // Free allocated memory
    return 0;
}

output:   



Single-Dimensional Array:
arr[0] = 1
arr[1] = 2
arr[2] = 3
arr[3] = 4
arr[4] = 5

Multidimensional Array (2D):
matrix[0][0] = 10
matrix[0][1] = 20
matrix[0][2] = 30
matrix[1][0] = 40
matrix[1][1] = 50
matrix[1][2] = 60

Enter size of dynamic array: 





#include <stdio.h>
#include <stdlib.h>

// -------------------- Arrays --------------------
void arrayExamples() {
    // 1. Single-Dimensional Array
    int arr[5] = {1, 2, 3, 4, 5};
    printf("Single-Dimensional Array:\n");
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    // 2. Multidimensional Array (2D)
    int matrix[2][3] = {
        {10, 20, 30},
        {40, 50, 60}
    };
    printf("\nMultidimensional Array (2D):\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("matrix[%d][%d] = %d\n", i, j, matrix[i][j]);
        }
    }

    // 3. Dynamic Size Array
    int size;
    printf("\nEnter size of dynamic array: ");
    scanf("%d", &size);

    int *dynArr = (int *)malloc(size * sizeof(int));
    if (dynArr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &dynArr[i]);
    }

    printf("Dynamic Array:\n");
    for (int i = 0; i < size; i++) {
        printf("dynArr[%d] = %d\n", i, dynArr[i]);
    }

    free(dynArr);
}

// -------------------- Singly Linked List --------------------
struct SNode {
    int data;
    struct SNode* next;
};

void insertS(struct SNode** head, int value) {
    struct SNode* newNode = (struct SNode*)malloc(sizeof(struct SNode));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct SNode* temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void displayS(struct SNode* head) {
    printf("\nSingly Linked List:\n");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// -------------------- Doubly Linked List --------------------
struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
};

void insertD(struct DNode** head, int value) {
    struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct DNode* temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void displayD(struct DNode* head) {
    printf("\nDoubly Linked List (forward):\n");
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// -------------------- Main --------------------
int main() {
    printf("=== Array Examples ===\n");
    arrayExamples();

    struct SNode* sHead = NULL;
    insertS(&sHead, 10);
    insertS(&sHead, 20);
    insertS(&sHead, 30);
    displayS(sHead);

    struct DNode* dHead = NULL;
    insertD(&dHead, 100);
    insertD(&dHead, 200);
    insertD(&dHead, 300);
    displayD(dHead);

    return 0;
}



output :




=== Array Examples ===
Single-Dimensional Array:
arr[0] = 1
arr[1] = 2
arr[2] = 3
arr[3] = 4
arr[4] = 5

Multidimensional Array (2D):
matrix[0][0] = 10
matrix[0][1] = 20
matrix[0][2] = 30
matrix[1][0] = 40
matrix[1][1] = 50
matrix[1][2] = 60

Enter size of dynamic array: 

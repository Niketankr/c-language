#include <stdio.h>
#include <stdlib.h>

// Node structure for singly linked list
struct Node {
    int data;               // data stored in node
    struct Node* next;      // pointer to next node
};

// Head pointer for the list
struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertAtHead(int val) {
    struct Node* newNode = createNode(val);
    newNode->next = head;
    head = newNode;
}

// Insert at end
void insertAtTail(int val) {
    struct Node* newNode = createNode(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Delete a node by value
void deleteNode(int val) {
    if (head == NULL) return;

    if (head->data == val) {
        struct Node* toDelete = head;
        head = head->next;
        free(toDelete);
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != val) {
        temp = temp->next;
    }

    if (temp->next == NULL) return;

    struct Node* toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
}

// Search for a value
int search(int val) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == val) return 1;
        temp = temp->next;
    }
    return 0;
}

// Display the list
void display() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Free all nodes
void freeList() {
    struct Node* temp = head;
    while (temp != NULL) {
        struct Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    head = NULL;
}

// Driver code
int main() {
    insertAtHead(10);
    insertAtHead(20);
    insertAtTail(30);
    insertAtTail(40);

    printf("Linked List: ");
    display();

    printf("Searching 30: %s\n", search(30) ? "Found" : "Not Found");

    deleteNode(20);
    printf("After deleting 20: ");
    display();

    deleteNode(40);
    printf("After deleting 40: ");
    display();

    freeList();
    return 0;
}
Linked List: 20 -> 10 -> 30 -> 40 -> NULL
Searching 30: Found
After deleting 20: 10 -> 30 -> 40 -> NULL
After deleting 40: 10 -> 30 -> NULL

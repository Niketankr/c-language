#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void insertAtBeginning(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}
void insertAtEnd(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}
void insertAtPosition(int data, int pos) {
    if (pos <= 1) {
        insertAtBeginning(data);
        return;
    }

    struct Node* newNode = createNode(data);
    struct Node* temp = head;

    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        insertAtEnd(data);
        return;
    }

    newNode->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
    newNode->prev = temp;
}

void deleteAtBeginning() {
    if (head == NULL) return;
    struct Node* temp = head;
    head = head->next;
    if (head != NULL) head->prev = NULL;
    free(temp);
}
void deleteAtEnd() {
    if (head == NULL) return;
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;
    free(temp);
}
void deleteAtPosition(int pos) {
    if (head == NULL) return;
    if (pos <= 1) {
        deleteAtBeginning();
        return;
    }

    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < pos; i++) {
        temp = temp->next;
    }
    if (temp == NULL) return;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}
void reverseList() {
    struct Node* current = head;
    struct Node* temp = NULL;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL)
        head = temp->prev;
}
void display() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    printf("Creating list using insert at end:\n");
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    display();

    printf("\nInsert at beginning (5):\n");
    insertAtBeginning(5);
    display();

    printf("\nInsert at end (40):\n");
    insertAtEnd(40);
    display();

    printf("\nInsert 25 at position 3:\n");
    insertAtPosition(25, 3);
    display();

    printf("\nDelete at beginning:\n");
    deleteAtBeginning();
    display();

    printf("\nDelete at end:\n");
    deleteAtEnd();
    display();

    printf("\nDelete at position 2:\n");
    deleteAtPosition(2);
    display();

    printf("\nReverse the list:\n");
    reverseList();
    display();

    return 0;
}

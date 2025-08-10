#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int stack[SIZE];
int top = -1; // Initialize top to -1 indicating an empty stack

// Function to push an element
void push() {
    int value;
    if (top == SIZE - 1) {
        printf("Stack Overflow! Cannot push more elements.\n");
    } else {
        printf("Enter value to push: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
        printf("Pushed %d onto the stack.\n", value);
    }
}

// Function to pop an element
void pop() {
    if (top == -1) {
        printf("Stack Underflow! No elements to pop.\n");
    } else {
        printf("Popped element: %d\n", stack[top]);
        top--;
    }
}

// Function to display the entire stack
void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements (Top to Bottom):\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

// Function to print the start (bottom) and end (top) elements
void printStartEnd() {
    if (top == -1) {
        printf("Stack is empty. No start or end elements to print.\n");
    } else {
        printf("Start element (bottom of stack): %d\n", stack[0]); 
        printf("End element (top of stack): %d\n", stack[top]);
    }
}

// Main function
int main() {
    int choice;
    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display All Elements\n");
        printf("4. Print Start and End Elements\n"); // New menu option
        printf("5. Exit\n"); 
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4: // New case for printing start and end elements
                printStartEnd();
                break;
            case 5: // Changed from 4 to 5 due to the new option
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

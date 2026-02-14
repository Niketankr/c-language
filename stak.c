#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/* -------------------------------
   QUEUE STRUCTURE
---------------------------------*/
typedef struct {
    int arr[MAX];
    int front;
    int rear;
} Queue;

/* -------------------------------
   FUNCTION DECLARATIONS
---------------------------------*/
void initQueue(Queue *q);
int isEmptyQueue(Queue *q);
int isFullQueue(Queue *q);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
int getFront(Queue *q);
void displayQueue(Queue *q);

/* Stack Using Two Queues */
void push(Queue *q1, Queue *q2, int value);
int pop(Queue *q1);
int top(Queue *q1);
void displayStack(Queue *q1);

/* -------------------------------
   MAIN FUNCTION
---------------------------------*/
int main() {
    Queue q1, q2;
    int choice, value;

    initQueue(&q1);
    initQueue(&q2);

    while (1) {
        printf("\n--- STACK USING QUEUES ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Top\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&q1, &q2, value);
                break;

            case 2:
                value = pop(&q1);
                if (value != -1)
                    printf("Popped element: %d\n", value);
                break;

            case 3:
                value = top(&q1);
                if (value != -1)
                    printf("Top element: %d\n", value);
                break;

            case 4:
                displayStack(&q1);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

/* -------------------------------
   QUEUE FUNCTIONS
---------------------------------*/
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmptyQueue(Queue *q) {
    return (q->front == -1);
}

int isFullQueue(Queue *q) {
    return (q->rear == MAX - 1);
}

void enqueue(Queue *q, int value) {
    if (isFullQueue(q)) {
        printf("Queue Overflow!\n");
        return;
    }

    if (q->front == -1)
        q->front = 0;

    q->rear++;
    q->arr[q->rear] = value;
}

int dequeue(Queue *q) {
    if (isEmptyQueue(q)) {
        printf("Queue Underflow!\n");
        return -1;
    }

    int value = q->arr[q->front];

    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;

    return value;
}

int getFront(Queue *q) {
    if (isEmptyQueue(q)) {
        printf("Stack is Empty!\n");
        return -1;
    }
    return q->arr[q->front];
}

/* -------------------------------
   STACK USING QUEUES FUNCTIONS
---------------------------------*/
void push(Queue *q1, Queue *q2, int value) {
    enqueue(q2, value);

    while (!isEmptyQueue(q1)) {
        enqueue(q2, dequeue(q1));
    }

    Queue temp = *q1;
    *q1 = *q2;
    *q2 = temp;

    printf("Element pushed successfully.\n");
}

int pop(Queue *q1) {
    if (isEmptyQueue(q1)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return dequeue(q1);
}

int top(Queue *q1) {
    return getFront(q1);
}

void displayStack(Queue *q1) {
    if (isEmptyQueue(q1)) {
        printf("Stack is Empty!\n");
        return;
    }

    printf("Stack elements:\n");
    for (int i = q1->front; i <= q1->rear; i++) {
        printf("%d ", q1->arr[i]);
    }
    printf("\n");
}


output:


--- STACK USING QUEUES ---
1. Push
2. Pop
3. Top
4. Display
5. Exit
Enter your choice: 1
Enter value to push: 10
Element pushed successfully.

--- STACK USING QUEUES ---
1. Push
2. Pop
3. Top
4. Display
5. Exit
Enter your choice: 
2
Popped element: 10

--- STACK USING QUEUES ---
1. Push
2. Pop
3. Top
4. Display
5. Exit
Enter your choice: 0
Invalid choice!

--- STACK USING QUEUES ---
1. Push
2. Pop
3. Top
4. Display
5. Exit
Enter your choice: 1
Enter value to push: 20
Element pushed successfully.


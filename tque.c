#include <stdio.h>

int stack[100];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

void pop() {
    top--;
}

int peek() {
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

int main() {
    int arr[] = {4, 5, 2, 25};
    int n = 4;
    int result[4];

    for (int i = n - 1; i >= 0; i--) {
        while (!isEmpty() && peek() <= arr[i])
            pop();

        result[i] = isEmpty() ? -1 : peek();
        push(arr[i]);
    }

    for (int i = 0; i < n; i++)
        printf("%d ", result[i]);

    return 0;
}

output:

5 25 25 -1 

#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 3

struct Node {
    int key;
    struct Node *prev, *next;
};

struct Node *head = NULL, *tail = NULL;

void moveToFront(struct Node *node) {
    if (node == head) return;

    if (node->prev)
        node->prev->next = node->next;
    if (node->next)
        node->next->prev = node->prev;

    if (node == tail)
        tail = node->prev;

    node->prev = NULL;
    node->next = head;
    if (head)
        head->prev = node;
    head = node;

    if (tail == NULL)
        tail = head;
}

void set(int key) {
    struct Node *temp = head;
    while (temp) {
        if (temp->key == key) {
            moveToFront(temp);
            return;
        }
        temp = temp->next;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->prev = NULL;
    newNode->next = head;

    if (head)
        head->prev = newNode;
    head = newNode;

    if (tail == NULL)
        tail = head;

    int count = 0;
    temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }

    if (count > CAPACITY) {
        struct Node *del = tail;
        tail = tail->prev;
        tail->next = NULL;
        free(del);
    }
}

void display() {
    struct Node *temp = head;
    while (temp) {
        printf("%d ", temp->key);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    set(1);
    set(2);
    set(3);
    display();

    set(4);
    display();

    set(2);
    display();

    return 0;
}

output:

3 2 1 
4 3 2 
2 4 3 


#include <stdio.h>

int stack[100], minStack[100];
int top = -1, minTop = -1;

void push(int x) {
    stack[++top] = x;
    if (minTop == -1 || x <= minStack[minTop])
        minStack[++minTop] = x;
}

void pop() {
    if (stack[top] == minStack[minTop])
        minTop--;
    top--;
}

int topElement() {
    return stack[top];
}

int getMin() {
    return minStack[minTop];
}

int main() {
    push(5);
    push(3);
    push(7);
    printf("Min: %d\n", getMin());
    pop();
    printf("Top: %d\n", topElement());
    printf("Min: %d\n", getMin());
    return 0;
}

output:

Min: 3
Top: 3
Min: 3

#include <stdio.h>
#include <stdlib.h>

int stack[100];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    char *tokens[] = {"2", "1", "+", "3", "*"};
    int n = 4;

    for (int i = 0; i < n; i++) {
        if (tokens[i][0] >= '0' && tokens[i][0] <= '9') {
            push(atoi(tokens[i]));
        } else {
            int b = pop();
            int a = pop();
            switch (tokens[i][0]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
    }

    printf("Result: %d\n", pop());
    return 0;
}

output:
Result: 3

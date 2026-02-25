#include <stdio.h>
#define MAX 100

int q1[MAX], q2[MAX];
int front1 = -1, rear1 = -1;
int front2 = -1, rear2 = -1;

int isEmpty1() {
    return front1 == -1;
}

void enqueue1(int x) {
    if (front1 == -1) front1 = 0;
    q1[++rear1] = x;
}

int dequeue1() {
    int x = q1[front1];
    if (front1 == rear1)
        front1 = rear1 = -1;
    else
        front1++;
    return x;
}

void enqueue2(int x) {
    if (front2 == -1) front2 = 0;
    q2[++rear2] = x;
}

int dequeue2() {
    int x = q2[front2];
    if (front2 == rear2)
        front2 = rear2 = -1;
    else
        front2++;
    return x;
}

void push(int x) {
    enqueue2(x);

    while (!isEmpty1())
        enqueue2(dequeue1());

    while (front2 != -1)
        enqueue1(dequeue2());
}

void pop() {
    if (!isEmpty1())
        dequeue1();
}

int top() {
    return q1[front1];
}

int main() {
    push(10);
    push(20);
    push(30);

    printf("Top: %d\n", top());
    pop();
    printf("Top after pop: %d\n", top());

    return 0;
}

output:
Top: 30
Top after pop: 20



Dequeue&Enqueque


  #include <stdio.h>
#define MAX 100

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

void push1(int x) {
    stack1[++top1] = x;
}

int pop1() {
    return stack1[top1--];
}

void push2(int x) {
    stack2[++top2] = x;
}

int pop2() {
    return stack2[top2--];
}

void enqueue(int x) {
    push1(x);
}

int dequeue() {
    if (top2 == -1) {
        while (top1 != -1)
            push2(pop1());
    }
    return pop2();
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("Dequeued: %d\n", dequeue());
    printf("Dequeued: %d\n", dequeue());
    

    return 0;
}

output:

Dequeued: 10
Dequeued: 20



  Next Greater Element


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

  Cache implimentation


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

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
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

int get(int key) {
    struct Node *temp = head;
    while (temp) {
        if (temp->key == key) {
            moveToFront(temp);
            return key;
        }
        temp = temp->next;
    }
    return -1;
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

    printf("Get 2: %d\n", get(2));
    display();

    return 0;
}

output:

3 2 1 
4 3 2 
Get 2: 2
2 4 3 

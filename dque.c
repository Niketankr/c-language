#include <stdio.h>
#define MAX 100

int q1[MAX], q2[MAX];
int f1 = -1, r1 = -1;
int f2 = -1, r2 = -1;


void enqueue(int q[], int *f, int *r, int x) {
    if (*r == MAX - 1)
        return;
    if (*f == -1)
        *f = 0;
    q[++(*r)] = x;
}

int dequeue(int q[], int *f, int *r) {
    int x;
    if (*f == -1)
        return -1;
    x = q[*f];
    if (*f == *r)
        *f = *r = -1;
    else
        (*f)++;
    return x;
}


void push(int x) {
    enqueue(q2, &f2, &r2, x);

    while (f1 != -1)
        enqueue(q2, &f2, &r2, dequeue(q1, &f1, &r1));


    int tempF = f1, tempR = r1;
    f1 = f2; r1 = r2;
    f2 = tempF; r2 = tempR;
}

void pop() {
    if (f1 == -1) {
        printf("Stack is Empty\n");
        return;
    }
    printf("Popped: %d\n", dequeue(q1, &f1, &r1));
}

void top() {
    if (f1 == -1) {
        printf("Stack is Empty\n");
        return;
    }
    printf("Top: %d\n", q1[f1]);
}

int main() {
    push(10);
    push(20);
    push(30);
    top();
    pop();
    top();
    return 0;
}

output:

Top: 0
Popped: 0
Top: 0


#include <stdio.h>
#define MAX 100

int s1[MAX], s2[MAX];
int top1 = -1, top2 = -1;


void push(int s[], int *top, int x) {
    if (*top == MAX - 1)
        return;
    s[++(*top)] = x;
}

int pop(int s[], int *top) {
    if (*top == -1)
        return -1;
    return s[(*top)--];
}


void enqueue(int x) {
    push(s1, &top1, x);
}

void dequeue() {
    int x;
    if (top1 == -1 && top2 == -1) {
        printf("Queue is Empty\n");
        return;
    }

    if (top2 == -1) {
        while (top1 != -1)
            push(s2, &top2, pop(s1, &top1));
    }

    x = pop(s2, &top2);
    printf("Dequeued: %d\n", x);
}

int main() {
    enqueue(5);
    enqueue(10);
    enqueue(15);
    dequeue();
    dequeue();
    return 0;
}

output:

Dequeued: 5
Dequeued: 10



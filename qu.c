#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

// -------------------- Normal Queue --------------------
int normalQueue[SIZE], frontN = -1, rearN = -1;

void enqueueNormal(int val) {
    if (rearN == SIZE - 1)
        printf("Normal Queue is full\n");
    else {
        if (frontN == -1) frontN = 0;
        normalQueue[++rearN] = val;
    }
}

void dequeueNormal() {
    if (frontN == -1 || frontN > rearN)
        printf("Normal Queue is empty\n");
    else
        printf("Normal Queue Dequeued: %d\n", normalQueue[frontN++]);
}

// -------------------- Queue Using Stacks --------------------
int stack1[SIZE], stack2[SIZE], top1 = -1, top2 = -1;

void push1(int val) { stack1[++top1] = val; }
int pop1() { return stack1[top1--]; }
void push2(int val) { stack2[++top2] = val; }
int pop2() { return stack2[top2--]; }

void enqueueStack(int val) { push1(val); }

void dequeueStack() {
    if (top2 == -1) {
        while (top1 != -1)
            push2(pop1());
    }
    if (top2 == -1)
        printf("Stack Queue is empty\n");
    else
        printf("Stack Queue Dequeued: %d\n", pop2());
}

// -------------------- Priority Queue --------------------
struct item {
    int value;
    int priority;
};

struct item pq[SIZE];
int countPQ = 0;

void enqueuePriority(int val, int pri) {
    if (countPQ == SIZE)
        printf("Priority Queue is full\n");
    else {
        pq[countPQ].value = val;
        pq[countPQ].priority = pri;
        countPQ++;
    }
}

void dequeuePriority() {
    if (countPQ == 0)
        printf("Priority Queue is empty\n");
    else {
        int highest = 0;
        for (int i = 1; i < countPQ; i++)
            if (pq[i].priority > pq[highest].priority)
                highest = i;
        printf("Priority Queue Dequeued: %d\n", pq[highest].value);
        for (int i = highest; i < countPQ - 1; i++)
            pq[i] = pq[i + 1];
        countPQ--;
    }
}

// -------------------- Double-Ended Queue --------------------
int deque[SIZE], frontD = -1, rearD = -1;

void insertFront(int val) {
    if (frontD == 0)
        printf("No space at front\n");
    else {
        if (frontD == -1) frontD = rearD = 0;
        else frontD--;
        deque[frontD] = val;
    }
}

void insertRear(int val) {
    if (rearD == SIZE - 1)
        printf("No space at rear\n");
    else {
        if (frontD == -1) frontD = rearD = 0;
        else rearD++;
        deque[rearD] = val;
    }
}

void deleteFront() {
    if (frontD == -1)
        printf("Deque is empty\n");
    else {
        printf("Deleted from front: %d\n", deque[frontD]);
        if (frontD == rearD) frontD = rearD = -1;
        else frontD++;
    }
}

void deleteRear() {
    if (rearD == -1)
        printf("Deque is empty\n");
    else {
        printf("Deleted from rear: %d\n", deque[rearD]);
        if (frontD == rearD) frontD = rearD = -1;
        else rearD--;
    }
}

// -------------------- Main --------------------
int main() {
    printf("=== Normal Queue ===\n");
    enqueueNormal(10); enqueueNormal(20); dequeueNormal(); dequeueNormal();

    printf("\n=== Queue Using Stacks ===\n");
    enqueueStack(30); enqueueStack(40); dequeueStack(); dequeueStack();

    printf("\n=== Priority Queue ===\n");
    enqueuePriority(50, 2); enqueuePriority(60, 5); dequeuePriority(); dequeuePriority();

    printf("\n=== Double-Ended Queue ===\n");
    insertRear(70); insertFront(80); deleteFront(); deleteRear();

    return 0;
}



output:

=== Normal Queue ===
Normal Queue Dequeued: 10
Normal Queue Dequeued: 20

=== Queue Using Stacks ===
Stack Queue Dequeued: 30
Stack Queue Dequeued: 40

=== Priority Queue ===
Priority Queue Dequeued: 60
Priority Queue Dequeued: 50

=== Double-Ended Queue ===
No space at front
Deleted from front: 70
Deque is empty


=== Code Execution Successful ===

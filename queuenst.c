#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

int isFull() {
    return (rear + 1) % SIZE == front;
}

int isEmpty() {
    return front == -1;
}

void enqueue(int value) {
    if(isFull()) {
        printf("Queue is Full\n");
        return;
    }

    if(front == -1)
        front = 0;

    rear = (rear + 1) % SIZE;
    queue[rear] = value;
}

void dequeue() {
    if(isEmpty()) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Removed: %d\n", queue[front]);

    if(front == rear)
        front = rear = -1;
    else
        front = (front + 1) % SIZE;
}

void display() {
    if(isEmpty()) return;

    int i = front;
    while(1) {
        printf("%d ", queue[i]);
        if(i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();
    dequeue();
    display();

    return 0;
}

output:
10 20 30 40 50 
Removed: 10
20 30 40 50 


#include <stdio.h>

#define MAX 100

int main() {
    int nums[] = {1,3,-1,-3,5,3,6,7};
    int n = 8;
    int k = 3;

    int deque[MAX];
    int front = 0, rear = -1;

    for(int i = 0; i < n; i++) {

 
        if(front <= rear && deque[front] <= i - k)
            front++;

 
        while(front <= rear && nums[deque[rear]] < nums[i])
            rear--;

        deque[++rear] = i;

        if(i >= k - 1)
            printf("%d ", nums[deque[front]]);
    }

    return 0;
}


output:

3 3 5 5 6 7 



#include <stdio.h>

#define N 4

int M[N][N] = {
    {0,1,1,0},
    {0,0,1,0},
    {0,0,0,0},
    {0,1,1,0}
};

int knows(int a, int b) {
    return M[a][b];
}

int findCelebrity() {
    int a = 0, b = N - 1;

    while(a < b) {
        if(knows(a,b))
            a++;
        else
            b--;
    }

    
    for(int i = 0; i < N; i++) {
        if(i != a && (knows(a,i) || !knows(i,a)))
            return -1;
    }

    return a;
}

int main() {
    int result = findCelebrity();

    if(result == -1)
        printf("No Celebrity\n");
    else
        printf("Celebrity is: %d\n", result);

    return 0;
}


output:

Celebrity is: 2

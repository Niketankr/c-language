#include <stdio.h>

#define MAX 100

int stack[MAX], minStack[MAX];
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

Reverse Polish Notation

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    char *tokens[] = {"2", "1", "+", "3", "*"};
    int n = 5;

    for (int i = 0; i < n; i++) {

        if (tokens[i][0] >= '0' && tokens[i][0] <= '5') {
            push(atoi(tokens[i]));
        } else {
            int b = pop();
            int a = pop();

            switch(tokens[i][0]) {
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

Result: 9

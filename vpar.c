#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push element onto stack
void push(char c) {
    stack[++top] = c;
}

// Pop element from stack
char pop() {
    return stack[top--];
}

// Check if opening and closing brackets match
int isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

// Function to check valid parentheses
int isValidParentheses(char expr[]) {
    for (int i = 0; i < strlen(expr); i++) {
        char ch = expr[i];

        // If opening bracket, push to stack
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }
        // If closing bracket
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1)  // No opening bracket
                return 0;

            char open = pop();
            if (!isMatchingPair(open, ch))
                return 0;
        }
    }

    // Stack should be empty at the end
    return top == -1;
}

int main() {
    char expr[MAX];

    printf("Enter expression: ");
    scanf("%s", expr);

    if (isValidParentheses(expr))
        printf("Valid parentheses\n");
    else
        printf("Invalid parentheses\n");

    return 0;
}

#include <stdio.h>
#include <string.h>

// Recursive function for factorial
int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

// Recursive function for Fibonacci
int fibonacci(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

// Recursive function for GCD
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Recursive function for sum of digits
int sumOfDigits(int n) {
    if (n == 0)
        return 0;
    return (n % 10) + sumOfDigits(n / 10);
}

// Recursive function to reverse a string
void reverseString(char str[], int start, int end) {
    if (start >= end)
        return;
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    reverseString(str, start + 1, end - 1);
}

// Recursive function for Tower of Hanoi
void towerOfHanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    towerOfHanoi(n - 1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    towerOfHanoi(n - 1, aux, to, from);
}

int main() {
    int choice, num, i;
    char str[100];

    while (1) {
        printf("\n--- Recursive Functions Menu ---\n");
        printf("1. Factorial\n");
        printf("2. Fibonacci Sequence\n");
        printf("3. GCD of two numbers\n");
        printf("4. Sum of digits\n");
        printf("5. Reverse a string\n");
        printf("6. Tower of Hanoi\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number: ");
                scanf("%d", &num);
                printf("Factorial of %d = %d\n", num, factorial(num));
                break;

            case 2:
                printf("Enter number of terms: ");
                scanf("%d", &num);
                printf("Fibonacci Sequence: ");
                for (i = 0; i < num; i++) {
                    printf("%d ", fibonacci(i));
                }
                printf("\n");
                break;

            case 3:
                {
                    int a, b;
                    printf("Enter two numbers: ");
                    scanf("%d %d", &a, &b);
                    printf("GCD of %d and %d = %d\n", a, b, gcd(a, b));
                }
                break;

            case 4:
                printf("Enter a number: ");
                scanf("%d", &num);
                printf("Sum of digits of %d = %d\n", num, sumOfDigits(num));
                break;

            case 5:
                printf("Enter a string: ");
                scanf("%s", str);
                reverseString(str, 0, strlen(str) - 1);
                printf("Reversed string: %s\n", str);
                break;

            case 6:
                printf("Enter number of disks: ");
                scanf("%d", &num);
                towerOfHanoi(num, 'A', 'C', 'B');
                break;

            case 7:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

#include <stdio.h>
#include <string.h>

int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int sumArray(int arr[], int n) {
    if (n == 0) return 0;
    return arr[n - 1] + sumArray(arr, n - 1);
}

void reverseString(char *s, int start, int end) {
    if (start >= end) return;
    char temp = s[start];
    s[start] = s[end];
    s[end] = temp;
    reverseString(s, start + 1, end - 1);
}

int binarySearch(int arr[], int low, int high, int target) {
    if (low > high) return -1;
    int mid = (low + high) / 2;
    if (arr[mid] == target) return mid;
    if (target < arr[mid]) return binarySearch(arr, low, mid - 1, target);
    return binarySearch(arr, mid + 1, high, target);
}

void printDown(int n) {
    if (n == 0) return;
    printf("%d ", n);
    printDown(n - 1);
}

void printUp(int n) {
    if (n == 0) return;
    printUp(n - 1);
    printf("%d ", n);
}

void subsets(int arr[], int n, int index, int curr[], int currSize) {
    if (index == n) {
        printf("{ ");
        for (int i = 0; i < currSize; i++) printf("%d ", curr[i]);
        printf("}\n");
        return;
    }
    curr[currSize] = arr[index];
    subsets(arr, n, index + 1, curr, currSize + 1);
    subsets(arr, n, index + 1, curr, currSize);
}

void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move %c -> %c\n", from, to);
        return;
    }
    hanoi(n - 1, from, aux, to);
    printf("Move %c -> %c\n", from, to);
    hanoi(n - 1, aux, to, from);
}

int countDigits(int n) {
    if (n == 0) return 0;
    return 1 + countDigits(n / 10);
}

int main() {
    printf("Factorial(5): %d\n", factorial(5));
    printf("Fibonacci(6): %d\n", fibonacci(6));

    int arr[] = {1, 2, 3, 4, 5};
    printf("Sum of array: %d\n", sumArray(arr, 5));

    char str[] = "recursion";
    reverseString(str, 0, strlen(str) - 1);
    printf("Reversed string: %s\n", str);

    int sorted[] = {1, 2, 3, 4, 5};
    printf("Binary search (4): %d\n", binarySearch(sorted, 0, 4, 4));

    printf("\nPrint down: ");
    printDown(5);

    printf("\nPrint up: ");
    printUp(5);

    int set[] = {1, 2, 3};
    int curr[3];
    printf("\nSubsets:\n");
    subsets(set, 3, 0, curr, 0);

    printf("\nTower of Hanoi (3 disks):\n");
    hanoi(3, 'A', 'C', 'B');

    printf("\nDigit count (12345): %d\n", countDigits(12345));

    return 0;
}
Factorial(5): 120
Fibonacci(6): 8
Sum of array: 15
Reversed string: noisrucer
Binary search (4): 3

Print down: 5 4 3 2 1 
Print up: 1 2 3 4 5 
Subsets:
{ 1 2 3 }
{ 1 2 }
{ 1 3 }
{ 1 }
{ 2 3 }
{ 2 }
{ 3 }
{ }

Tower of Hanoi (3 disks):
Move A -> C
Move A -> B
Move C -> B
Move A -> C
Move B -> A
Move B -> C
Move A -> C

Digit count (12345): 5


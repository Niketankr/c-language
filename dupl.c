#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 100

// Function prototypes
void findDuplicates(int arr[], int n);
int maxSubarrayProduct(int arr[], int n);

int main() {
    int n, i;
    int arr[MAX_SIZE];

    printf("Enter number of elements (max 100): ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_SIZE) {
        printf("Invalid size!\n");
        return 1;
    }

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\n--- Duplicate Elements ---\n");
    findDuplicates(arr, n);

    printf("\n--- Maximum Product Subarray ---\n");
    int maxProduct = maxSubarrayProduct(arr, n);
    printf("Maximum product of a subarray: %d\n", maxProduct);

    return 0;
}

// Find and print duplicates in the array
void findDuplicates(int arr[], int n) {
    int i, j;
    int found = 0;

    printf("Duplicates in the array: ");
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            // If duplicate found
            if (arr[i] == arr[j]) {
                printf("%d ", arr[i]);
                found = 1;
                break; // move to next element
            }
        }
    }
    if (!found) {
        printf("None");
    }
    printf("\n");
}

// Find maximum product subarray (brute force)
int maxSubarrayProduct(int arr[], int n) {
    int maxProduct = arr[0];
    for (int i = 0; i < n; i++) {
        int product = 1;
        for (int j = i; j < n; j++) {
            product *= arr[j];
            if (product > maxProduct) {
                maxProduct = product;
            }
        }
    }
    return maxProduct;
}


output:


--- Duplicate Elements ---
Duplicates in the array: 546 2 9 4 7 5 5 4 5 5 6 4 4 5 4 4 4 4 5 2 21 4 1 4 5 2 5 0 0 0 

--- Maximum Product Subarray ---
Maximum product of a subarray: 2127134720

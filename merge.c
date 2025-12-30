#include <stdio.h>
#include <stdint.h>

// Calculate array size macro
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

// Recursive GCD function for juggling algorithm
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Print array elements
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Left rotate array by k positions using juggling algorithm
void leftRotate(int arr[], int k, int n) {
    // Handle k >= n case
    k = k % n;
    
    int g = gcd(k, n);
    
    // Rotate g sets of elements
    for (int i = 0; i < g; i++) {
        int temp = arr[i];
        int j = i;
        
        while (1) {
            int next = j + k;
            if (next >= n) {
                next = next - n;
            }
            if (next == i) {
                break;
            }
            arr[j] = arr[next];
            j = next;
        }
        arr[j] = temp;
    }
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5, 6, 7};
    int n1 = ARRAY_SIZE(arr1);
    int k1 = 2;
    
    printf("Original array: ");
    printArray(arr1, n1);
    
    leftRotate(arr1, k1, n1);
    printf("After left rotate by %d: ", k1);
    printArray(arr1, n1);
    
    // Test case 2
    int arr2[] = {8, 11, 13, 15, 1, 4, 6};
    int n2 = ARRAY_SIZE(arr2);
    int k2 = 3;
    
    printf("\nTest case 2 - Original: ");
    printArray(arr2, n2);
    leftRotate(arr2, k2, n2);
    printf("After left rotate by %d: ", k2);
    printArray(arr2, n2);
    
    return 0;
}


output:



Original array: 1 2 3 4 5 6 7 
After left rotate by 2: 3 4 5 6 7 1 2 

Test case 2 - Original: 8 11 13 15 1 4 6 
After left rotate by 3: 15 1 4 6 8 11 13 

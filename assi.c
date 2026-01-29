#include <stdio.h>

void findPair(int arr[], int n, int X) {
    int left = 0;
    int right = n - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == X) {
            printf("Pair found: %d and %d\n", arr[left], arr[right]);
            return;
        } 
        else if (sum < X) {
            left++;
        } 
        else {
            right--;
        }
    }

    printf("No pair found with sum %d\n", X);
}

int main() {
    int arr[] = {1, 2, 4, 7, 11, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int X = 15;

    findPair(arr, n, X);
    return 0;
}


output:
Pair found: 4 and 11


#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key) {
    if (low <= high) {
        int mid = low + (high - low) / 2;

        
        if (arr[mid] == key)
            return mid;

        
        if (arr[mid] > key)
            return binarySearch(arr, low, mid - 1, key);

        
        return binarySearch(arr, mid + 1, high, key);
    }

   
    return -1;
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 23;

    int result = binarySearch(arr, 0, n - 1, key);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}


output:
Element found at index 5


#include <stdio.h>

int binarySearch2D(int A[][3], int N, int M, int key) {
    int low = 0;
    int high = N * M - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        int row = mid / M;
        int col = mid % M;

        if (A[row][col] == key)
            return 1;  

        else if (A[row][col] < key)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return 0;
}

int main() {
    int A[3][3] = {
        {1, 3, 5},
        {7, 9, 11},
        {13, 15, 17}
    };

    int key = 9;

    if (binarySearch2D(A, 3, 3, key))
        printf("Element found\n");
    else
        printf("Element not found\n");

    return 0;
}


output:
Element found

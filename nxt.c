#include <stdio.h>

int main() {
    int height[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n = 12;

    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int water = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] >= leftMax)
                leftMax = height[left];
            else
                water += leftMax - height[left];
            left++;
        } else {
            if (height[right] >= rightMax)
                rightMax = height[right];
            else
                water += rightMax - height[right];
            right--;
        }
    }

    printf("Trapped Water = %d\n", water);
    return 0;
}

output:

Trapped Water = 6


#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int arr[], int start, int end) {
    while (start < end) {
        swap(&arr[start], &arr[end]);
        start++;
        end--;
    }
}

void nextPermutation(int arr[], int n) {
    int i = n - 2;

    while (i >= 0 && arr[i] >= arr[i + 1])
        i--;

    if (i >= 0) {
        int j = n - 1;
        while (arr[j] <= arr[i])
            j--;
        swap(&arr[i], &arr[j]);
    }

    reverse(arr, i + 1, n - 1);
}

int main() {
    int arr[] = {1, 2, 3};
    int n = 3;

    nextPermutation(arr, n);

    printf("Next Permutation: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

output:

Next Permutation: 1 3 2 

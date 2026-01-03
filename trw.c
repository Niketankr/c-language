#include <stdio.h>

// ----------------------------------------------------
// Trapping Rain Water
// ----------------------------------------------------
int trapRainWater(int height[], int n) {
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
    return water;
}

// ----------------------------------------------------
// Next Permutation
// ----------------------------------------------------
void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void nextPermutation(int arr[], int n) {
    int i = n - 2;

    // Step 1: Find first decreasing element
    while (i >= 0 && arr[i] >= arr[i + 1])
        i--;

    if (i >= 0) {
        int j = n - 1;

        // Step 2: Find just larger element
        while (arr[j] <= arr[i])
            j--;

        // Step 3: Swap
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // Step 4: Reverse remaining part
    reverse(arr, i + 1, n - 1);
}

// ----------------------------------------------------
// Main Function
// ----------------------------------------------------
int main() {
    // Trapping Rain Water example
    int height[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n1 = sizeof(height) / sizeof(height[0]);
    printf("Trapped Rain Water: %d\n", trapRainWater(height, n1));

    // Next Permutation example
    int nums[] = {1, 2, 3};
    int n2 = sizeof(nums) / sizeof(nums[0]);

    nextPermutation(nums, n2);

    printf("Next Permutation: ");
    for (int i = 0; i < n2; i++)
        printf("%d ", nums[i]);
    printf("\n");

    return 0;
}
output :


Trapped Rain Water: 6
Next Permutation: 1 3 2 

#include <stdio.h>
#include <limits.h>

struct Result {
    int min1, min2;
    int max1, max2;
};

struct Result findMinMax(int arr[], int low, int high) {
    struct Result res, left, right;

    // Case 1: Only one element
    if (low == high) {
        res.min1 = res.max1 = arr[low];
        res.min2 = INT_MAX;
        res.max2 = INT_MIN;
        return res;
    }

    // Case 2: Two elements
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            res.min1 = arr[low];
            res.min2 = arr[high];
            res.max1 = arr[high];
            res.max2 = arr[low];
        } else {
            res.min1 = arr[high];
            res.min2 = arr[low];
            res.max1 = arr[low];
            res.max2 = arr[high];
        }
        return res;
    }

    // Case 3: More than two elements
    int mid = (low + high) / 2;

    left = findMinMax(arr, low, mid);
    right = findMinMax(arr, mid + 1, high);

    // Find first minimum
    if (left.min1 < right.min1) {
        res.min1 = left.min1;
        res.min2 = (left.min2 < right.min1) ? left.min2 : right.min1;
    } else {
        res.min1 = right.min1;
        res.min2 = (right.min2 < left.min1) ? right.min2 : left.min1;
    }

    // Find first maximum
    if (left.max1 > right.max1) {
        res.max1 = left.max1;
        res.max2 = (left.max2 > right.max1) ? left.max2 : right.max1;
    } else {
        res.max1 = right.max1;
        res.max2 = (right.max2 > left.max1) ? right.max2 : left.max1;
    }

    return res;
}

int main() {
    int arr[] = {7, 2, 9, 4, 1, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (n < 2) {
        printf("Array must have at least two elements.\n");
        return 0;
    }

    struct Result ans = findMinMax(arr, 0, n - 1);

    printf("1st Minimum  : %d\n", ans.min1);
    printf("2nd Minimum  : %d\n", ans.min2);
    printf("1st Maximum  : %d\n", ans.max1);
    printf("2nd Maximum  : %d\n", ans.max2);

    return 0;
}

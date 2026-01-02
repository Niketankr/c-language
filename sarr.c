#include <stdio.h>
#include <stdlib.h>   // FIX: required for abs()

// Function to find missing and repeating number
void findMissingAndRepeating(int arr[], int n)
{
    int i;
    int repeat = -1, missing = -1;

    for (i = 0; i < n; i++)
    {
        int index = abs(arr[i]) - 1;

        if (arr[index] < 0)
            repeat = abs(arr[i]);
        else
            arr[index] = -arr[index];
    }

    for (i = 0; i < n; i++)
    {
        if (arr[i] > 0)
            missing = i + 1;
    }

    printf("Repeating Number: %d\n", repeat);
    printf("Missing Number  : %d\n", missing);
}

// Function to find subarray with given sum
void subarrayWithSum(int arr[], int n, int sum)
{
    int currSum = arr[0];
    int start = 0;

    for (int end = 1; end <= n; end++)
    {
        while (currSum > sum && start < end - 1)
        {
            currSum -= arr[start];
            start++;
        }

        if (currSum == sum)
        {
            printf("Subarray found from index %d to %d\n", start, end - 1);
            return;
        }

        if (end < n)
            currSum += arr[end];
    }

    printf("No subarray with given sum found\n");
}

int main()
{
    int arr1[] = {4, 3, 6, 2, 1, 1};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    printf("Missing and Repeating Number Problem:\n");
    findMissingAndRepeating(arr1, n1);

    int arr2[] = {1, 4, 20, 3, 10, 5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int sum = 33;

    printf("\nSubarray With Given Sum Problem:\n");
    subarrayWithSum(arr2, n2, sum);

    return 0;
}
output:


Missing and Repeating Number Problem:
Repeating Number: 1
Missing Number  : 5

Subarray With Given Sum Problem:
Subarray found from index 2 to 4

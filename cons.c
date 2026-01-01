#include <stdio.h>
#include <stdlib.h>

/* Function to find subarray with given sum */
void subarrayWithSum(int arr[], int n, int sum)
{
    int currSum = arr[0], start = 0;

    for (int i = 1; i <= n; i++)
    {
        while (currSum > sum && start < i - 1)
        {
            currSum -= arr[start];
            start++;
        }

        if (currSum == sum)
        {
            printf("Subarray with given sum found from index %d to %d\n",
                   start, i - 1);
            return;
        }

        if (i < n)
            currSum += arr[i];
    }

    printf("No subarray with given sum found\n");
}

/* Comparison function for qsort */
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

/* Function to find longest consecutive sequence */
void longestConsecutiveSequence(int arr[], int n)
{
    if (n == 0)
        return;

    qsort(arr, n, sizeof(int), compare);

    int longest = 1, current = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1] + 1)
        {
            current++;
        }
        else if (arr[i] != arr[i - 1])
        {
            if (current > longest)
                longest = current;
            current = 1;
        }
    }

    if (current > longest)
        longest = current;

    printf("Length of longest consecutive sequence: %d\n", longest);
}

int main()
{
    int arr1[] = {1, 4, 20, 3, 10, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int sum = 33;

    printf("Subarray With Given Sum Problem:\n");
    subarrayWithSum(arr1, n1, sum);

    int arr2[] = {100, 4, 200, 1, 3, 2};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    printf("\nLongest Consecutive Sequence Problem:\n");
    longestConsecutiveSequence(arr2, n2);

    return 0;
}




output:

Subarray With Given Sum Problem:
Subarray with given sum found from index 2 to 4

Longest Consecutive Sequence Problem:
Length of longest consecutive sequence: 4

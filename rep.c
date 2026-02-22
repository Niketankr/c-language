#include <stdio.h>

int main() {
    int n = 5;
    int arr[] = {1, 3, 3, 5, 4};
    int freq[6] = {0};   

    int missing, repeating;

    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    for (int i = 1; i <= n; i++) {
        if (freq[i] == 0)
            missing = i;
        if (freq[i] == 2)
            repeating = i;
    }

    printf("Missing = %d\n", missing);
    printf("Repeating = %d\n", repeating);

    return 0;
}

output:
Missing = 2
Repeating = 3


#include <stdio.h>

int main() {
    int arr[] = {11, 12, 13, 17, 25};
    int n = 15, sum = 21;

    int currSum = arr[0], start = 0;

    for (int end = 1; end <= n; end++) {

        while (currSum > sum && start < end - 1) {
            currSum -= arr[start];
            start++;
        }

        if (currSum == sum) {
            printf("Subarray found from index %d to %d\n", start + 1, end);
            return 0;
        }

        if (end < n)
            currSum += arr[end];
    }

    printf("No subarray found\n");
    return 0;
}

output:
Subarray found from index 8 to 8



#include <stdio.h>

void sort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {100, 4, 200, 1, 3, 2};
    int n = 6;

    sort(arr, n);

    int longest = 1, curr = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1] + 1) {
            curr++;
        } else if (arr[i] != arr[i - 1]) {
            curr = 1;
        }
        if (curr > longest)
            longest = curr;
    }

    printf("Longest Consecutive Sequence Length = %d\n", longest);

    return 0;
}

output:
Longest Consecutive Sequence Length = 4



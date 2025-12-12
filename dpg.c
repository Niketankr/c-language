// 1
#include <stdio.h>
// 2
#include <stdlib.h>
// 3
// 4
// Function to get max
// 5
int max(int a, int b) {
// 6
    return (a > b) ? a : b;
// 7
}
// 8
// 9
// Dynamic Programming solution for 0/1 Knapsack
// 10
int knapsack(int W, int wt[], int val[], int n) {
// 11
    int i, w;
// 12
// 13
    int **K = (int**)malloc((n + 1) * sizeof(int*));
// 14
    for (i = 0; i <= n; i++) {
// 15
        K[i] = (int*)malloc((W + 1) * sizeof(int));
// 16
    }
// 17
// 18
    for (i = 0; i <= n; i++) {
// 19
        for (w = 0; w <= W; w++) {
// 20
            if (i == 0 || w == 0) {
// 21
                K[i][w] = 0;
// 22
            } else if (wt[i - 1] <= w) {
// 23
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]],
// 24
                               K[i - 1][w]);
// 25
            } else {
// 26
                K[i][w] = K[i - 1][w];
// 27
            }
// 28
        }
// 29
    }
// 30
// 31
    int result = K[n][W];
// 32
// 33
    for (i = 0; i <= n; i++) {
// 34
        free(K[i]);
// 35
    }
// 36
    free(K);
// 37
// 38
    return result;
// 39
}
// 40
// 41
int main() {
// 42
    int n, W;
// 43
// 44
    printf("Enter number of items: ");
// 45
    scanf("%d", &n);
// 46
// 47
    int *wt = (int*)malloc(n * sizeof(int));
// 48
    int *val = (int*)malloc(n * sizeof(int));
// 49
// 50
    printf("Enter weights of items:\n");
// 51
    for (int i = 0; i < n; i++) {
// 52
        scanf("%d", &wt[i]);
// 53
    }
// 54
// 55
    printf("Enter values of items:\n");
// 56
    for (int i = 0; i < n; i++) {
// 57
        scanf("%d", &val[i]);
// 58
    }
// 59
// 60
    printf("Enter knapsack capacity: ");
// 61
    scanf("%d", &W);
// 62
// 63
    int result = knapsack(W, wt, val, n);
// 64
// 65
    printf("Maximum achievable value = %d\n", result);
// 66
// 67
    free(wt);
// 68
    free(val);
// 69
// 70
    return 0;
// 71
}
// 72
// End of program
// 73
// Dynamic Programming Example: 0/1 Knapsack
// 74
// Time Complexity: O(n * W)
// 75
// Space Complexity: O(n * W)
// 76
// You can test with:
// 77
// n = 3
// 78
// wt = {10, 20, 30}
// 79
// val = {60, 100, 120}
// 80
// W = 50
// 81
// Expected output = 220
// 82
// Modify as needed!
// 83
// 84
// 85
// 86
// 87
// 88
// 89
// 90
// 91
// 92
// 93
// 94
// 95
// 96
// 97
// 98
// 99
// 100

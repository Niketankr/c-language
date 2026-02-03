#include <stdio.h>
#include <limits.h>

#define MAX 100

int m[MAX][MAX];  // Cost table
int s[MAX][MAX];  // Split table

/* Function to print optimal parenthesization */
void printOptimalParens(int i, int j) {
    if (i == j) {
        printf("A%d", i);
        return;
    }
    printf("(");
    printOptimalParens(i, s[i][j]);
    printOptimalParens(s[i][j] + 1, j);
    printf(")");
}

/* Matrix Chain Order function */
void matrixChainOrder(int p[], int n) {
    int i, j, k, L;
    int q;

    // Cost is zero when multiplying one matrix
    for (i = 1; i <= n; i++)
        m[i][i] = 0;

    // L is chain length
    for (L = 2; L <= n; L++) {
        for (i = 1; i <= n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX;

            for (k = i; k < j; k++) {
                q = m[i][k] + m[k + 1][j] +
                    p[i - 1] * p[k] * p[j];

                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("Minimum number of multiplications: %d\n", m[1][n]);
    printf("Optimal Parenthesization: ");
    printOptimalParens(1, n);
    printf("\n");
}

/* Driver code */
int main() {
    int p[] = {10, 30, 5, 60};
    int n = sizeof(p) / sizeof(p[0]) - 1;

    matrixChainOrder(p, n);

    return 0;
}

output:

Minimum number of multiplications: 4500
Optimal Parenthesization: ((A1A2)A3)



#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int wt[], int val[], int n) {
    int dp[n + 1][W + 1];

    // Build DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(
                    val[i - 1] + dp[i - 1][w - wt[i - 1]],
                    dp[i - 1][w]
                );
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][W];
}

int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);

    printf("Maximum value in Knapsack = %d\n",
           knapsack(W, wt, val, n));

    return 0;
}

output:

Maximum value in Knapsack = 220


=== Code Execution Successful ===

#include <stdio.h>

struct Job {
    int id;
    int deadline;
    int profit;
};


void swap(struct Job *a, struct Job *b) {
    struct Job temp = *a;
    *a = *b;
    *b = temp;
}


void sortByProfit(struct Job jobs[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (jobs[j].profit < jobs[j + 1].profit) {
                swap(&jobs[j], &jobs[j + 1]);
            }
        }
    }
}


void jobSequencing(struct Job jobs[], int n) {
    sortByProfit(jobs, n);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

    int slot[maxDeadline + 1];
    for (int i = 0; i <= maxDeadline; i++)
        slot[i] = -1;

    int totalProfit = 0;

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (slot[j] == -1) {
                slot[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    printf("Job sequence: ");
    for (int i = 1; i <= maxDeadline; i++) {
        if (slot[i] != -1)
            printf("J%d ", slot[i]);
    }

    printf("\nTotal Profit: %d\n", totalProfit);
}


int main() {
    struct Job jobs[] = {
        {1, 2, 100},
        {2, 1, 19},
        {3, 2, 27},
        {4, 1, 25},
        {5, 3, 15}
    };

    int n = sizeof(jobs) / sizeof(jobs[0]);

    jobSequencing(jobs, n);

    return 0;
}

output:

Job sequence: J3 J1 J5 
Total Profit: 142


=== Code Execution Successful ===

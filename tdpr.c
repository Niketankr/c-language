#include <stdio.h>

int subsetSum(int arr[], int n, int sum) {
    int dp[n + 1][sum + 1];

    
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int j = 1; j <= sum; j++)
        dp[0][j] = 0;

    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
        }
    }

    return dp[n][sum];
}

int main() {
    int arr[] = {3, 34, 4, 12, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 9;

    if (subsetSum(arr, n, sum))
        printf("Subset with given sum exists\n");
    else
        printf("No subset with given sum exists\n");

    return 0;
}

output:

Subset with given sum exists


=== Code Execution Successful ===


#include <stdio.h>
#include <limits.h>
#include <math.h>

#define MAXN 10
#define INF 1000000000

int n;
int dist[MAXN][MAXN];
int dp[1 << MAXN][MAXN];

int min(int a, int b) {
    return (a < b) ? a : b;
}

int tsp() {
    int VISITED_ALL = (1 << n) - 1;

    
    for (int mask = 0; mask < (1 << n); mask++)
        for (int i = 0; i < n; i++)
            dp[mask][i] = INF;

    dp[1][0] = 0; 

    for (int mask = 1; mask <= VISITED_ALL; mask++) {
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                for (int j = 0; j < n; j++) {
                    if ((mask & (1 << j)) && j != i) {
                        dp[mask][i] = min(
                            dp[mask][i],
                            dp[mask ^ (1 << i)][j] + dist[j][i]
                        );
                    }
                }
            }
        }
    }

    int ans = INF;
    for (int i = 1; i < n; i++) {
        ans = min(ans, dp[VISITED_ALL][i] + dist[i][0]);
    }

    return ans;
}

int main() {
    n = 4;

    int input[4][4] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = input[i][j];

    printf("Minimum cost of TSP = %d\n", tsp());

    return 0;
}


output:

Minimum cost of TSP = 80


=== Code Execution Successful ===

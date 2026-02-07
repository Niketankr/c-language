#include <stdio.h>
#include <limits.h>

#define R 3
#define C 3


int min(int a, int b, int c) {
    int t = (a < b) ? a : b;
    return (t < c) ? t : c;
}


int minCostPath(int cost[R][C], int m, int n) {
    int dp[R][C];

    dp[0][0] = cost[0][0];

    
    for (int i = 1; i <= m; i++)
        dp[i][0] = dp[i - 1][0] + cost[i][0];

    
    for (int j = 1; j <= n; j++)
        dp[0][j] = dp[0][j - 1] + cost[0][j];

    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = cost[i][j] +
                       min(dp[i - 1][j],
                           dp[i][j - 1],
                           dp[i - 1][j - 1]);
        }
    }

    return dp[m][n];
}

int main() {
    int cost[R][C] = {
        {1, 2, 3},
        {4, 8, 2},
        {1, 5, 3}
    };

    int m = 2, n = 2;

    printf("Minimum cost to reach (%d, %d) = %d\n",
           m, n, minCostPath(cost, m, n));

    return 0;
}


output:

Minimum cost to reach (2, 2) = 8


=== Code Execution Successful ===




#include <stdio.h>
#include <limits.h>

int minCoins(int coins[], int m, int V) {
    int dp[V + 1];

  
    for (int i = 1; i <= V; i++)
        dp[i] = INT_MAX;

    dp[0] = 0;

    
    for (int i = 1; i <= V; i++) {
        for (int j = 0; j < m; j++) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                if (dp[i] > dp[i - coins[j]] + 1)
                    dp[i] = dp[i - coins[j]] + 1;
            }
        }
    }

    return dp[V];
}

int main() {
    int coins[] = {1, 2, 5, 10};
    int m = sizeof(coins) / sizeof(coins[0]);
    int V = 23;

    int result = minCoins(coins, m, V);

    if (result == INT_MAX)
        printf("Change cannot be made\n");
    else
        printf("Minimum number of coins required = %d\n", result);

    return 0;
}


output:

Minimum number of coins required = 4


=== Code Execution Successful ===

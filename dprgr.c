#include <stdio.h>
#include <limits.h>

#define V 4

void longestPath(int graph[V][V], int src) {
    int dp[V];

    // Initialize DP array
    for (int i = 0; i < V; i++)
        dp[i] = INT_MIN;

    dp[src] = 0;

    // Relax edges in topological order
    for (int u = 0; u < V; u++) {
        if (dp[u] != INT_MIN) {
            for (int v = 0; v < V; v++) {
                if (graph[u][v] != 0) {
                    if (dp[v] < dp[u] + graph[u][v]) {
                        dp[v] = dp[u] + graph[u][v];
                    }
                }
            }
        }
    }

    // Print results
    printf("Longest distances from source %d:\n", src);
    for (int i = 0; i < V; i++)
        printf("Node %d : %d\n", i, dp[i]);
}

int main() {
    int graph[V][V] = {
        {0, 1, 1, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 1},
        {0, 0, 0, 0}
    };

    longestPath(graph, 0);
    return 0;
}


output:

Longest distances from source 0:
Node 0 : 0
Node 1 : 1
Node 2 : 1
Node 3 : 2




For 8 nodes:


#include <stdio.h>
#include <limits.h>

#define V 8

void longestPath(int graph[V][V], int src) {
    int dp[V];

    
    for (int i = 0; i < V; i++)
        dp[i] = INT_MIN;

    dp[src] = 0;

    
    for (int u = 0; u < V; u++) {
        if (dp[u] != INT_MIN) {
            for (int v = 0; v < V; v++) {
                if (graph[u][v] != 0) {
                    if (dp[v] < dp[u] + graph[u][v]) {
                        dp[v] = dp[u] + graph[u][v];
                    }
                }
            }
        }
    }

    
    printf("Longest distances from source %d:\n", src);
    for (int i = 0; i < V; i++) {
        if (dp[i] == INT_MIN)
            printf("Node %d : Not reachable\n", i);
        else
            printf("Node %d : %d\n", i, dp[i]);
    }
}

int main() {
    int graph[V][V] = {
        {0, 2, 3, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 4, 1, 0, 0, 0}, 
        {0, 0, 0, 0, 2, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 3, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 4, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 2}, 
        {0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0} 
    };

    longestPath(graph, 0);
    return 0;
}



output:


Longest distances from source 0:
Node 0 : 0
Node 1 : 2
Node 2 : 3
Node 3 : 6
Node 4 : 5
Node 5 : 9
Node 6 : 9
Node 7 : 11


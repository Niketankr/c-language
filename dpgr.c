#include <stdio.h>

#define V 5
#define INF 99999

// Function to print the distance matrix
void printSolution(int dist[V][V]) {
    int i, j;
    printf("Shortest distances between every pair of vertices:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

// Floyd-Warshall algorithm (Dynamic Programming)
void floydWarshall(int graph[V][V]) {
    int dist[V][V];
    int i, j, k;

    // Initialize distance matrix
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // Main DP logic
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    printSolution(dist);
}

int main() {
    int graph[V][V] = {
        {0,   3,   INF, 7,   INF},
        {8,   0,   2,   INF, INF},
        {5,   INF, 0,   1,   INF},
        {2,   INF, INF, 0,   1},
        {INF, INF, INF, INF, 0}
    };

    floydWarshall(graph);

    return 0;
}
Shortest distances between every pair of vertices:
      0      3      5      6      7
      5      0      2      3      4
      3      6      0      1      2
      2      5      7      0      1
    INF    INF    INF    INF      0



#include <stdio.h>

#define V 6
#define INF 99999

// Function to display the matrix
void printMatrix(int dist[V][V]) {
    int i, j;
    printf("\nShortest path matrix:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%6s", "INF");
            else
                printf("%6d", dist[i][j]);
        }
        printf("\n");
    }
}

// Floyd Warshall Algorithm (Dynamic Programming)
void floydWarshall(int graph[V][V]) {
    int dist[V][V];
    int i, j, k;

    // Initialize distance matrix
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // DP logic
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][k] != INF &&
                    dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printMatrix(dist);
}

int main() {
    int graph[V][V] = {
        {0,   4,   INF, INF, INF, 10},
        {INF, 0,   3,   INF, INF, INF},
        {INF, INF, 0,   2,   INF, INF},
        {INF, INF, INF, 0,   6,   INF},
        {INF, INF, INF, INF, 0,   1},
        {INF, INF, INF, INF, INF, 0}
    };

    printf("Floyd Warshall Algorithm using Dynamic Programming\n");
    floydWarshall(graph);

    return 0;
}
Floyd Warshall Algorithm using Dynamic Programming

Shortest path matrix:
     0     4     7     9    15    10
   INF     0     3     5    11    12
   INF   INF     0     2     8     9
   INF   INF   INF     0     6     7
   INF   INF   INF   INF     0     1
   INF   INF   INF   INF   INF     0

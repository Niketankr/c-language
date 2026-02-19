#include <stdio.h>

#define MAX 10

int queue[MAX], front = -1, rear = -1;
int visited[MAX];

void enqueue(int x) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear || front == -1;
}

void BFS(int graph[MAX][MAX], int start, int n) {
    int i;
    enqueue(start);
    visited[start] = 1;

    while (!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);

        for (i = 0; i < n; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n = 5, start = 0;
    int graph[MAX][MAX] = {
        {0,1,0,1,0},
        {1,0,1,0,1},
        {0,1,0,0,0},
        {1,0,0,0,1},
        {0,1,0,1,0}
    };

    BFS(graph, start, n);
    return 0;
}



#include <stdio.h>

#define MAX 10

int visited[MAX];

void DFS(int graph[MAX][MAX], int node, int n) {
    int i;
    visited[node] = 1;
    printf("%d ", node);

    for (i = 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            DFS(graph, i, n);
        }
    }
}

int main() {
    int n = 5, start = 0;
    int graph[MAX][MAX] = {
        {0,1,0,1,0},
        {1,0,1,0,1},
        {0,1,0,0,0},
        {1,0,0,0,1},
        {0,1,0,1,0}
    };

    DFS(graph, start, n);
    return 0;
}



#include <stdio.h>

#define MAX 10

int visited[MAX];
int recStack[MAX];

int isCyclicUtil(int graph[MAX][MAX], int node, int n) {
    int i;

    if (!visited[node]) {
        visited[node] = 1;
        recStack[node] = 1;

        for (i = 0; i < n; i++) {
            if (graph[node][i] == 1) {
                if (!visited[i] && isCyclicUtil(graph, i, n))
                    return 1;
                else if (recStack[i])
                    return 1;
            }
        }
    }
    recStack[node] = 0;
    return 0;
}

int isCyclic(int graph[MAX][MAX], int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (isCyclicUtil(graph, i, n))
            return 1;
    }
    return 0;
}

int main() {
    int n = 4;
    int graph[MAX][MAX] = {
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,1},
        {1,0,0,0}  
    };

    if (isCyclic(graph, n))
        printf("Cycle Exists\n");
    else
        printf("No Cycle\n");

    return 0;
}

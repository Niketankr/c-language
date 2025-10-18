#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int visited[MAX];
int queue[MAX], front = -1, rear = -1;

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
};

// Create a node
struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct Node*));

    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

// Add edge
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // For undirected graph
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// DFS
void DFS(struct Graph* graph, int vertex) {
    struct Node* adjList = graph->adjLists[vertex];
    struct Node* temp = adjList;

    visited[vertex] = 1;
    printf("%d ", vertex);

    while (temp != NULL) {
        int connectedVertex = temp->vertex;

        if (!visited[connectedVertex])
            DFS(graph, connectedVertex);

        temp = temp->next;
    }
}

// BFS
void enqueue(int value) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = value;
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

void BFS(struct Graph* graph, int startVertex) {
    for (int i = 0; i < MAX; i++)
        visited[i] = 0;

    enqueue(startVertex);
    visited[startVertex] = 1;

    while (front <= rear) {
        int currentVertex = dequeue();
        printf("%d ", currentVertex);

        struct Node* temp = graph->adjLists[currentVertex];

        while (temp) {
            int adjVertex = temp->vertex;

            if (!visited[adjVertex]) {
                enqueue(adjVertex);
                visited[adjVertex] = 1;
            }
            temp = temp->next;
        }
    }
}

int main() {
    struct Graph* graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);

    printf("DFS traversal:\n");
    for (int i = 0; i < MAX; i++) visited[i] = 0;
    DFS(graph, 0);

    printf("\n\nBFS traversal:\n");
    BFS(graph, 0);

    return 0;
}

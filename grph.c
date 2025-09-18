#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

// 1. Structure for a node in the adjacency list
struct Node {
    int data;
    struct Node* next;
};

// 2. Structure for the graph
struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited;
};

// Function to create a new node
struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// 3. Function to create a graph of V vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    
    // Create an array of adjacency lists
    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    graph->visited = malloc(vertices * sizeof(int));
    
    // Initialize adjacency lists and visited array
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// 4. Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from source to destination
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    
    // Add edge from destination to source (for an undirected graph)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// 5. Function to perform Breadth-First Search (BFS) Traversal
void BFS(struct Graph* graph, int startVertex) {
    // Create a queue for BFS
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    graph->visited[startVertex] = 1;
    queue[rear++] = startVertex;
    
    printf("BFS Traversal starting from vertex %d: ", startVertex);

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);
        
        struct Node* temp = graph->adjLists[currentVertex];
        
        while (temp) {
            int adjVertex = temp->data;
            
            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

// 6. Function to print the graph
void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        struct Node* temp = graph->adjLists[v];
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (temp) {
            printf("-> %d", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function to demonstrate graph operations
int main() {
    struct Graph* graph = createGraph(5); // A graph with 5 vertices
    
    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    
    // Print the graph's structure
    printf("Graph Representation:\n");
    printGraph(graph);
    
    // Perform BFS traversal
    BFS(graph, 0);
    
    return 0;
}

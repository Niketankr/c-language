#include <stdio.h>
#include <limits.h>

#define V 5  

int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    int visited[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main() {
    int graph[V][V] = {
        {0, 10, 0, 0, 5},
        {0, 0, 1, 0, 2},
        {0, 0, 0, 4, 0},
        {7, 0, 6, 0, 0},
        {0, 3, 9, 2, 0}
    };

    dijkstra(graph, 0);
    return 0;
}



output:

Vertex 	 Distance from Source
0 		 0
1 		 8
2 		 9
3 		 7
4 		 5


#include <stdio.h>
#include <limits.h>

#define V 7   
#define E 8   

struct Edge {
    int src, dest, weight;
};

void bellmanFord(struct Edge edges[], int src) {
    int dist[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

   
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }


    for (int j = 0; j < E; j++) {
        int u = edges[j].src;
        int v = edges[j].dest;
        int w = edges[j].weight;

        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }

    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main() {
    struct Edge edges[E] = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    bellmanFord(edges, 0);
    return 0;
}


output:

Vertex 	 Distance from Source
0 		 0
1 		 -1
2 		 2
3 		 -2
4 		 1
5 		 2147483647
6 		 2147483647



#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXV 5   


struct AdjNode {
    int dest;
    int weight;
    struct AdjNode* next;
};


struct AdjList {
    struct AdjNode* head;
};


struct Graph {
    int numVertices;
    struct AdjList* array;
};


struct MinHeapNode {
    int v;
    int dist;
};


struct MinHeap {
    int size;
    int capacity;
    int* pos;
    struct MinHeapNode** array;
};


struct AdjNode* newAdjNode(int dest, int weight) {
    struct AdjNode* node = malloc(sizeof(struct AdjNode));
    node->dest = dest;
    node->weight = weight;
    node->next = NULL;
    return node;
}


struct Graph* createGraph(int numVertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->array = malloc(numVertices * sizeof(struct AdjList));

    for (int i = 0; i < numVertices; i++)
        graph->array[i].head = NULL;

    return graph;
}


void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct AdjNode* node = newAdjNode(dest, weight);
    node->next = graph->array[src].head;
    graph->array[src].head = node;
}


struct MinHeapNode* newMinHeapNode(int v, int dist) {
    struct MinHeapNode* node = malloc(sizeof(struct MinHeapNode));
    node->v = v;
    node->dist = dist;
    return node;
}


struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* minHeap = malloc(sizeof(struct MinHeap));
    minHeap->pos = malloc(capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = malloc(capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}


void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* temp = *a;
    *a = *b;
    *b = temp;
}


void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size &&
        minHeap->array[left]->dist < minHeap->array[smallest]->dist)
        smallest = left;

    if (right < minHeap->size &&
        minHeap->array[right]->dist < minHeap->array[smallest]->dist)
        smallest = right;

    if (smallest != idx) {
        minHeap->pos[minHeap->array[smallest]->v] = idx;
        minHeap->pos[minHeap->array[idx]->v] = smallest;

        swapMinHeapNode(&minHeap->array[smallest],
                        &minHeap->array[idx]);

        minHeapify(minHeap, smallest);
    }
}

int isEmpty(struct MinHeap* minHeap) {
    return minHeap->size == 0;
}


struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
    if (isEmpty(minHeap))
        return NULL;

    struct MinHeapNode* root = minHeap->array[0];
    struct MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;

    minHeap->pos[root->v] = minHeap->size - 1;
    minHeap->pos[lastNode->v] = 0;

    minHeap->size--;
    minHeapify(minHeap, 0);

    return root;
}


void decreaseKey(struct MinHeap* minHeap, int v, int dist) {
    int i = minHeap->pos[v];
    minHeap->array[i]->dist = dist;

    while (i && minHeap->array[i]->dist <
                minHeap->array[(i - 1) / 2]->dist) {

        minHeap->pos[minHeap->array[i]->v] = (i - 1) / 2;
        minHeap->pos[minHeap->array[(i - 1) / 2]->v] = i;

        swapMinHeapNode(&minHeap->array[i],
                        &minHeap->array[(i - 1) / 2]);

        i = (i - 1) / 2;
    }
}


int isInMinHeap(struct MinHeap* minHeap, int v) {
    return minHeap->pos[v] < minHeap->size;
}

// Dijkstra algorithm
void dijkstra(struct Graph* graph, int src) {
    int numVertices = graph->numVertices;
    int dist[MAXV];

    struct MinHeap* minHeap = createMinHeap(numVertices);

    for (int v = 0; v < numVertices; v++) {
        dist[v] = INT_MAX;
        minHeap->array[v] = newMinHeapNode(v, dist[v]);
        minHeap->pos[v] = v;
    }

    minHeap->array[src] = newMinHeapNode(src, 0);
    minHeap->pos[src] = src;
    dist[src] = 0;
    decreaseKey(minHeap, src, 0);

    minHeap->size = numVertices;

    while (!isEmpty(minHeap)) {
        struct MinHeapNode* minNode = extractMin(minHeap);
        int u = minNode->v;

        struct AdjNode* crawl = graph->array[u].head;
        while (crawl != NULL) {
            int v = crawl->dest;

            if (isInMinHeap(minHeap, v) &&
                dist[u] != INT_MAX &&
                crawl->weight + dist[u] < dist[v]) {

                dist[v] = dist[u] + crawl->weight;
                decreaseKey(minHeap, v, dist[v]);
            }
            crawl = crawl->next;
        }
    }

    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < numVertices; i++)
        printf("%d\t%d\n", i, dist[i]);
}


int main() {
    struct Graph* graph = createGraph(MAXV);

    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 4, 5);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 1, 4, 2);
    addEdge(graph, 2, 3, 4);
    addEdge(graph, 3, 0, 7);
    addEdge(graph, 4, 1, 3);
    addEdge(graph, 4, 2, 9);
    addEdge(graph, 4, 3, 2);

    dijkstra(graph, 0);
    return 0;
}


output:

Vertex	Distance from Source
0	0
1	8
2	9
3	7
4	5


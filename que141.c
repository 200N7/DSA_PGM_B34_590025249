/*Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

/* Node for adjacency list */
struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

/* Graph structure */
struct Graph {
    int V;
    struct Node** adjLists;
};

/* Min Heap Node */
struct HeapNode {
    int vertex;
    int dist;
};

/* Min Heap */
struct MinHeap {
    int size;
    struct HeapNode heap[MAX];
};

/* Create graph */
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    graph->adjLists = (struct Node**)malloc(V * sizeof(struct Node*));

    for (int i = 0; i < V; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

/* Create new node */
struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

/* Add edge (UNDIRECTED) */
void addEdge(struct Graph* graph, int u, int v, int w) {
    struct Node* newNode = createNode(v, w);
    newNode->next = graph->adjLists[u];
    graph->adjLists[u] = newNode;

    newNode = createNode(u, w);
    newNode->next = graph->adjLists[v];
    graph->adjLists[v] = newNode;
}

/* Swap heap nodes */
void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

/* Heapify */
void heapify(struct MinHeap* h, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < h->size && h->heap[left].dist < h->heap[smallest].dist)
        smallest = left;

    if (right < h->size && h->heap[right].dist < h->heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&h->heap[i], &h->heap[smallest]);
        heapify(h, smallest);
    }
}

/* Extract min */
struct HeapNode extractMin(struct MinHeap* h) {
    struct HeapNode root = h->heap[0];
    h->heap[0] = h->heap[h->size - 1];
    h->size--;
    heapify(h, 0);
    return root;
}

/* Insert into heap */
void insertHeap(struct MinHeap* h, int v, int dist) {
    int i = h->size++;
    h->heap[i].vertex = v;
    h->heap[i].dist = dist;

    /* Fix min heap */
    while (i && h->heap[(i - 1) / 2].dist > h->heap[i].dist) {
        swap(&h->heap[i], &h->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

/* Check empty */
int isEmpty(struct MinHeap* h) {
    return h->size == 0;
}

/* Dijkstra Algorithm */
void dijkstra(struct Graph* graph, int src) {
    int dist[MAX];

    /* Initialize distances */
    for (int i = 0; i < graph->V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    struct MinHeap h;
    h.size = 0;

    insertHeap(&h, src, 0);

    while (!isEmpty(&h)) {
        struct HeapNode node = extractMin(&h);
        int u = node.vertex;

        struct Node* temp = graph->adjLists[u];

        while (temp) {
            int v = temp->vertex;
            int weight = temp->weight;

            /* Relaxation */
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                insertHeap(&h, v, dist[v]);
            }

            temp = temp->next;
        }
    }

    /* Print result */
    for (int i = 0; i < graph->V; i++) {
        printf("Distance from %d to %d = %d\n", src, i, dist[i]);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Graph* graph = createGraph(n);

    int u, v, w;

    /* Input edges */
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        addEdge(graph, u, v, w);
    }

    int src;
    scanf("%d", &src);

    dijkstra(graph, src);

    return 0;
}
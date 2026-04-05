/*Problem: Perform BFS from a given source using queue.

Input:
- n
- adjacency list
- source s

Output:
- BFS traversal order*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/* Node for adjacency list */
struct Node {
    int vertex;
    struct Node* next;
};

/* Graph structure */
struct Graph {
    int V;
    struct Node** adjLists;
};

/* Queue implementation */
int queue[MAX];
int front = 0, rear = -1;

/* Create node */
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

/* Create graph */
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    graph->adjLists = (struct Node**)malloc(V * sizeof(struct Node*));

    for (int i = 0; i < V; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

/* Add edge (undirected) */
void addEdge(struct Graph* graph, int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = graph->adjLists[u];
    graph->adjLists[u] = newNode;

    newNode = createNode(u);
    newNode->next = graph->adjLists[v];
    graph->adjLists[v] = newNode;
}

/* Queue operations */
void enqueue(int x) { queue[++rear] = x; }
int dequeue() { return queue[front++]; }
int isEmpty() { return front > rear; }

/* BFS function */
void BFS(struct Graph* graph, int start, int visited[]) {
    enqueue(start);
    visited[start] = 1;

    while (!isEmpty()) {
        int curr = dequeue();

        /* Print node */
        printf("%d ", curr);

        struct Node* temp = graph->adjLists[curr];

        /* Visit all neighbors */
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
    int n, m;
    scanf("%d %d", &n, &m);

    struct Graph* graph = createGraph(n);

    int u, v;

    /* Input edges */
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    int start;
    scanf("%d", &start);

    int visited[MAX] = {0};

    /* Call BFS */
    BFS(graph, start, visited);

    return 0;
}
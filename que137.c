/*Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.*/

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

/* Stack */
int stack[MAX];
int top = -1;

/* Push to stack */
void push(int x) {
    stack[++top] = x;
}

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

/* Add edge (DIRECTED) */
void addEdge(struct Graph* graph, int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = graph->adjLists[u];
    graph->adjLists[u] = newNode;
}

/* DFS for Topological Sort */
void topoDFS(struct Graph* graph, int v, int visited[]) {
    visited[v] = 1;

    struct Node* temp = graph->adjLists[v];

    /* Visit all neighbors */
    while (temp) {
        if (!visited[temp->vertex])
            topoDFS(graph, temp->vertex, visited);

        temp = temp->next;
    }

    /* Push after visiting children */
    push(v);
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

    int visited[MAX] = {0};

    /* Call DFS for all nodes */
    for (int i = 0; i < n; i++) {
        if (!visited[i])
            topoDFS(graph, i, visited);
    }

    /* Print stack (reverse order) */
    while (top != -1) {
        printf("%d ", stack[top--]);
    }

    return 0;
}
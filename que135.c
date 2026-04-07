/*Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists*/

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

/* DFS function to detect cycle */
int hasCycle(struct Graph* graph, int v, int visited[], int recStack[]) {
    visited[v] = 1;
    recStack[v] = 1;

    struct Node* temp = graph->adjLists[v];

    while (temp) {
        int adj = temp->vertex;

        /* If not visited → recurse */
        if (!visited[adj]) {
            if (hasCycle(graph, adj, visited, recStack))
                return 1;
        }
        /* If in recursion stack → cycle */
        else if (recStack[adj]) {
            return 1;
        }

        temp = temp->next;
    }

    /* Remove from recursion stack */
    recStack[v] = 0;

    return 0;
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
    int recStack[MAX] = {0};
    int cycle = 0;

    /* Check all components */
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (hasCycle(graph, i, visited, recStack)) {
                cycle = 1;
                break;
            }
        }
    }

    if (cycle)
        printf("YES");
    else
        printf("NO");

    return 0;
}
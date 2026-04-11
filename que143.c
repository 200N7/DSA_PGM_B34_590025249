/*Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.

Input:
- n vertices
- m edges (u,v,w)

Output:
- Shortest distances OR NEGATIVE CYCLE*/

#include <stdio.h>
#include <limits.h>

#define MAX 100

/* Edge structure */
struct Edge {
    int u, v, w;
};

/* Bellman-Ford Algorithm */
void bellmanFord(int n, int m, struct Edge edges[], int src) {
    int dist[MAX];

    /* Step 1: Initialize distances */
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    /* Step 2: Relax all edges (n-1 times) */
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    /* Step 3: Check for negative cycle */
    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            printf("NEGATIVE CYCLE");
            return;
        }
    }

    /* Step 4: Print distances */
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            printf("INF ");
        else
            printf("%d ", dist[i]);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Edge edges[MAX];

    /* Input edges */
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    int src;
    scanf("%d", &src);

    bellmanFord(n, m, edges, src);

    return 0;
}
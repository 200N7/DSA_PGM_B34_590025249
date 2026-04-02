/*Problem: Build a graph with n vertices and m edges using adjacency matrix representation.
The graph may be directed or undirected.

Input:
- n (vertices)
- m (edges)
- m pairs (u, v)

Output:
- n x n adjacency matrix*/

#include <stdio.h>

#define MAX 100

int main() {
    int n, m;
    
    /* Input number of vertices and edges */
    scanf("%d %d", &n, &m);

    int adj[MAX][MAX];

    /* Step 1: Initialize matrix with 0 */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    int u, v;

    /* Step 2: Take edges as input */
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        /* Add edge (undirected) */
        adj[u][v] = 1;
        adj[v][u] = 1;

        /* 
        For directed graph, use only:
        adj[u][v] = 1;
        */
    }

    /* Step 3: Print adjacency matrix */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}
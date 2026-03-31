#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1005

int main() {
    int n, m;
    int graph[MAX][MAX];
    int key[MAX];     // Minimum weight edge to reach this node
    int mstSet[MAX];  // To track vertices included in MST

    if (scanf("%d %d", &n, &m) != 2) return 0;

    // Initialize graph with a large value (infinity)
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = (i == j) ? 0 : INT_MAX;
        }
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    // Read edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        // Handle multiple edges between same nodes: keep the smallest
        if (w < graph[u][v]) {
            graph[u][v] = w;
            graph[v][u] = w;
        }
    }

    // Prim's Logic
    key[1] = 0; // Starting with the first node
    int totalWeight = 0;

    for (int count = 0; count < n; count++) {
        // Pick the minimum key vertex from the set of vertices not yet in MST
        int u = -1;
        int min = INT_MAX;

        for (int v = 1; v <= n; v++) {
            if (!mstSet[v] && key[v] < min) {
                min = key[v];
                u = v;
            }
        }

        if (u == -1) break; // Graph is disconnected

        // Add the picked vertex to the MST Set
        mstSet[u] = 1;
        totalWeight += key[u];

        // Update key values of adjacent vertices
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] != INT_MAX && !mstSet[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    printf("%d\n", totalWeight);

    return 0;
}

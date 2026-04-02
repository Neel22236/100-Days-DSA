#include <stdio.h>

#define MAX 100
#define INF 1e9 // Using a large value to represent infinity

void floydWarshall(int n, int dist[MAX][MAX]) {
    // k is the intermediate vertex
    for (int k = 0; k < n; k++) {
        // i is the source vertex
        for (int i = 0; i < n; i++) {
            // j is the destination vertex
            for (int j = 0; j < n; j++) {
                // If vertex k can provide a shorter path from i to j
                // we update the distance. We check INF to avoid overflow.
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
}

int main() {
    int n;
    int dist[MAX][MAX];

    if (scanf("%d", &n) != 1) return 0;

    // Read adjacency matrix and prepare distance matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val;
            scanf("%d", &val);
            if (val == -1) {
                dist[i][j] = INF;
            } else {
                dist[i][j] = val;
            }
        }
    }

    // Run the algorithm
    floydWarshall(n, dist);

    // Print the resulting shortest distance matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] >= INF) {
                printf("-1 ");
            } else {
                printf("%d ", dist[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

// Adjacency list node structure
struct Node {
    int dest;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];
int reached_count = 0;

// Add edge for an undirected graph
void addEdge(int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = v;
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = u;
    newNode->next = adj[v];
    adj[v] = newNode;
}

// DFS to explore the graph and count visited nodes
void DFS(int v) {
    visited[v] = 1;
    reached_count++;
    struct Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->dest]) {
            DFS(temp->dest);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    // Handle edge case for empty graph with nodes
    if (n == 0) return 0;

    // Initialize
    for (int i = 1; i <= n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        // Only add edges if they are within valid node range
        if (u <= n && v <= n) {
            addEdge(u, v);
        }
    }

    // Start DFS from the first node
    DFS(1);

    // If reached_count equals total nodes, it's connected
    if (reached_count == n) {
        printf("CONNECTED\n");
    } else {
        printf("NOT CONNECTED\n");
    }

    return 0;
}

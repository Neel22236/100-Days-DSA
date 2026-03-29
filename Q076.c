#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

// Adjacency list node
struct Node {
    int dest;
    struct Node* next;
};

// Array to track visited nodes and adjacency list head pointers
struct Node* adj[MAX];
int visited[MAX];

// Function to add an edge to the adjacency list
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

// DFS to mark all nodes in the current component
void DFS(int v) {
    visited[v] = 1;
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

    // Initialize adjacency list and visited array
    for (int i = 1; i <= n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    // Read edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    int components = 0;

    // Traverse all vertices
    for (int i = 1; i <= n; i++) {
        // If vertex i is not visited, it's the start of a new component
        if (!visited[i]) {
            components++;
            DFS(i);
        }
    }

    printf("%d\n", components);

    return 0;
}

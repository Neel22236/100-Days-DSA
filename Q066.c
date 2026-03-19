#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node* adj[], int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

int dfs(int v, int visited[], int recStack[], Node* adj[]) {
    visited[v] = 1;
    recStack[v] = 1;

    Node* temp = adj[v];
    while (temp) {
        int u = temp->vertex;

        if (!visited[u]) {
            if (dfs(u, visited, recStack, adj))
                return 1;
        } else if (recStack[u]) {
            return 1;
        }

        temp = temp->next;
    }

    recStack[v] = 0;
    return 0;
}

int hasCycle(int n, Node* adj[]) {
    int visited[n], recStack[n];

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, visited, recStack, adj))
                return 1;
        }
    }

    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Node* adj[n];
    for (int i = 0; i < n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    if (hasCycle(n, adj)) printf("YES\n");
    else printf("NO\n");

    return 0;
}
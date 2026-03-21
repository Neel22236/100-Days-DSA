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

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Node* adj[n];
    for (int i = 0; i < n; i++) adj[i] = NULL;

    int indegree[n];
    for (int i = 0; i < n; i++) indegree[i] = 0;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
        indegree[v]++;
    }

    int queue[n];
    int front = 0, rear = 0;

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;

    while (front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);
        count++;

        Node* temp = adj[curr];
        while (temp) {
            int v = temp->vertex;
            indegree[v]--;

            if (indegree[v] == 0) {
                queue[rear++] = v;
            }
            temp = temp->next;
        }
    }

    if (count != n) {
        printf("\nCycle detected\n");
    }

    return 0;
}
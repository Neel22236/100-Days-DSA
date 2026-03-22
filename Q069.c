#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int vertex, weight;
    struct Node* next;
} Node;

Node* createNode(int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node* adj[], int u, int v, int w) {
    Node* newNode = createNode(v, w);
    newNode->next = adj[u];
    adj[u] = newNode;
}

typedef struct {
    int v, dist;
} Pair;

void swap(Pair* a, Pair* b) {
    Pair temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(Pair heap[], int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (heap[parent].dist <= heap[idx].dist) break;
        swap(&heap[parent], &heap[idx]);
        idx = parent;
    }
}

void heapifyDown(Pair heap[], int size, int idx) {
    while (1) {
        int smallest = idx;
        int left = 2*idx + 1;
        int right = 2*idx + 2;

        if (left < size && heap[left].dist < heap[smallest].dist)
            smallest = left;
        if (right < size && heap[right].dist < heap[smallest].dist)
            smallest = right;

        if (smallest == idx) break;
        swap(&heap[idx], &heap[smallest]);
        idx = smallest;
    }
}

void push(Pair heap[], int* size, int v, int dist) {
    heap[*size].v = v;
    heap[*size].dist = dist;
    (*size)++;
    heapifyUp(heap, *size - 1);
}

Pair pop(Pair heap[], int* size) {
    Pair root = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    heapifyDown(heap, *size, 0);
    return root;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Node* adj[n];
    for (int i = 0; i < n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(adj, u, v, w);
    }

    int src;
    scanf("%d", &src);

    int dist[n];
    for (int i = 0; i < n; i++) dist[i] = INT_MAX;

    Pair heap[n * m];
    int size = 0;

    dist[src] = 0;
    push(heap, &size, src, 0);

    while (size > 0) {
        Pair curr = pop(heap, &size);
        int u = curr.v;
        int d = curr.dist;

        if (d > dist[u]) continue;

        Node* temp = adj[u];
        while (temp) {
            int v = temp->vertex;
            int w = temp->weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(heap, &size, v, dist[v]);
            }

            temp = temp->next;
        }
    }

    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) printf("INF ");
        else printf("%d ", dist[i]);
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100005

typedef struct {
    int node;
    int dist;
} Element;

typedef struct Node {
    int dest, weight;
    struct Node* next;
} Node;

Node* adj[MAX];
int dist[MAX];

// Priority Queue (Min-Heap) implementation
Element heap[MAX * 4];
int heapSize = 0;

void push(int node, int d) {
    int i = ++heapSize;
    while (i > 1 && heap[i / 2].dist > d) {
        heap[i] = heap[i / 2];
        i /= 2;
    }
    heap[i].node = node;
    heap[i].dist = d;
}

Element pop() {
    Element top = heap[1];
    Element last = heap[heapSize--];
    int i = 1, child;
    while (i * 2 <= heapSize) {
        child = i * 2;
        if (child != heapSize && heap[child + 1].dist < heap[child].dist) child++;
        if (last.dist > heap[child].dist) heap[i] = heap[child];
        else break;
        i = child;
    }
    heap[i] = last;
    return top;
}

void addEdge(int u, int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = v;
    newNode->weight = w;
    newNode->next = adj[u];
    adj[u] = newNode;
}

void dijkstra(int startNode, int n) {
    for (int i = 1; i <= n; i++) dist[i] = INT_MAX;
    dist[startNode] = 0;
    push(startNode, 0);

    while (heapSize > 0) {
        Element current = pop();
        int u = current.node;
        int d = current.dist;

        if (d > dist[u]) continue;

        Node* temp = adj[u];
        while (temp) {
            if (dist[u] + temp->weight < dist[temp->dest]) {
                dist[temp->dest] = dist[u] + temp->weight;
                push(temp->dest, dist[temp->dest]);
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n, m, source;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, w); // Assuming undirected based on common graph problems
    }
    scanf("%d", &source);

    dijkstra(source, n);

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) printf("INF ");
        else printf("%d ", dist[i]);
    }
    printf("\n");

    return 0;
}

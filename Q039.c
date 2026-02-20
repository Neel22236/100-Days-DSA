#include <stdio.h>
#include <string.h>

#define MAX 100000

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int val) {
    heap[size] = val;
    int curr = size;
    size++;
    while (curr > 0) {
        int parent = (curr - 1) / 2;
        if (heap[parent] > heap[curr]) {
            swap(&heap[parent], &heap[curr]);
            curr = parent;
        } else {
            break;
        }
    }
}

int extractMin() {
    if (size == 0) {
        return -1;
    }
    int res = heap[0];
    heap[0] = heap[size - 1];
    size--;
    int curr = 0;
    
    while (1) {
        int left = 2 * curr + 1;
        int right = 2 * curr + 2;
        int smallest = curr;
        
        if (left < size && heap[left] < heap[smallest]) {
            smallest = left;
        }
        if (right < size && heap[right] < heap[smallest]) {
            smallest = right;
        }
        if (smallest != curr) {
            swap(&heap[curr], &heap[smallest]);
            curr = smallest;
        } else {
            break;
        }
    }
    return res;
}

int peek() {
    if (size == 0) {
        return -1;
    }
    return heap[0];
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }
    
    for (int i = 0; i < n; i++) {
        char op[15];
        scanf("%14s", op);
        
        if (strcmp(op, "insert") == 0) {
            int val;
            scanf("%d", &val);
            insert(val);
        } else if (strcmp(op, "extractMin") == 0) {
            printf("%d\n", extractMin());
        } else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        }
    }
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Meeting;

// Comparator to sort meetings by start time
int compareMeetings(const void* a, const void* b) {
    return (((Meeting*)a)->start - ((Meeting*)b)->start);
}

// Simple Min-Heap implementation to manage end times
void heapify(int heap[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest]) smallest = left;
    if (right < size && heap[right] < heap[smallest]) smallest = right;

    if (smallest != i) {
        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        heapify(heap, size, smallest);
    }
}

void push(int heap[], int* size, int value) {
    heap[*size] = value;
    int i = *size;
    (*size)++;

    // Perk up
    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

void pop(int heap[], int* size) {
    heap[0] = heap[*size - 1];
    (*size)--;
    heapify(heap, *size, 0);
}

int minMeetingRooms(Meeting* meetings, int n) {
    if (n == 0) return 0;

    // 1. Sort meetings by start time
    qsort(meetings, n, sizeof(Meeting), compareMeetings);

    // 2. Allocate heap for end times
    int* minHeap = (int*)malloc(n * sizeof(int));
    int heapSize = 0;

    // 3. Process meetings
    push(minHeap, &heapSize, meetings[0].end);

    for (int i = 1; i < n; i++) {
        // If the earliest meeting ends before the current one starts, reuse room
        if (meetings[i].start >= minHeap[0]) {
            pop(minHeap, &heapSize);
        }
        // Always push the current meeting's end time
        push(minHeap, &heapSize, meetings[i].end);
    }

    int result = heapSize;
    free(minHeap);
    return result;
}

int main() {
    Meeting meetings[] = {{0, 30}, {5, 10}, {15, 20}};
    int n = sizeof(meetings) / sizeof(meetings[0]);

    printf("Minimum rooms required: %d\n", minMeetingRooms(meetings, n));
    return 0;
}

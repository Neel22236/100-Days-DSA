#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort to sort stall positions
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Greedy function to check if we can place k cows with at least 'minDist' between them
int isPossible(int stalls[], int n, int k, int minDist) {
    int cowsPlaced = 1; // Place the first cow at the first stall
    int lastPos = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastPos >= minDist) {
            cowsPlaced++;
            lastPos = stalls[i]; // Update the position of the last placed cow
            if (cowsPlaced >= k) return 1;
        }
    }
    return 0;
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;

    int stalls[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }

    // 1. Sort the stalls to process them linearly
    qsort(stalls, n, sizeof(int), compare);

    // 2. Binary search on the possible distance range
    int low = 1; // Minimum possible distance
    int high = stalls[n - 1] - stalls[0]; // Maximum possible distance
    int result = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(stalls, n, k, mid)) {
            result = mid;   // This distance works, try to find a larger one
            low = mid + 1;
        } else {
            high = mid - 1; // Too far apart, try a smaller distance
        }
    }

    printf("%d\n", result);

    return 0;
}

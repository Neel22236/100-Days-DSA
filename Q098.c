#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

// Comparator to sort intervals by start time
int compareIntervals(const void* a, const void* b) {
    Interval* i1 = (Interval*)a;
    Interval* i2 = (Interval*)b;
    return i1->start - i2->start;
}

// Helper to get maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

void mergeIntervals(Interval intervals[], int n) {
    if (n <= 0) return;

    // 1. Sort intervals based on start time
    qsort(intervals, n, sizeof(Interval), compareIntervals);

    // 2. Use the first interval as the starting point
    int index = 0; // Tracks the position in the merged set

    for (int i = 1; i < n; i++) {
        // If current interval overlaps with the previous merged one
        // (i.e., start of current <= end of previous)
        if (intervals[index].end >= intervals[i].start) {
            // Merge by updating the end time to the maximum found so far
            intervals[index].end = max(intervals[index].end, intervals[i].end);
        } else {
            // No overlap, move to the next index and update it
            index++;
            intervals[index] = intervals[i];
        }
    }

    // 3. Print the merged intervals
    printf("Merged Intervals:\n");
    for (int i = 0; i <= index; i++) {
        printf("[%d, %d] ", intervals[i].start, intervals[i].end);
    }
    printf("\n");
}

int main() {
    // Example: [[1,3], [2,6], [8,10], [15,18]]
    Interval arr[] = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeIntervals(arr, n);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Merges two sorted subarrays and counts cross-inversions
long long mergeAndCount(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    long long inversions = 0;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            // L[i] > R[j], so R[j] is smaller than all elements from L[i] to L[n1-1]
            arr[k++] = R[j++];
            inversions += (n1 - i);
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
    return inversions;
}

// Recursive function to sort and count inversions
long long countInversions(int arr[], int l, int r) {
    long long count = 0;
    if (l < r) {
        int m = l + (r - l) / 2;

        count += countInversions(arr, l, m);       // Left half
        count += countInversions(arr, m + 1, r);   // Right half
        count += mergeAndCount(arr, l, m, r);      // Cross inversions
    }
    return count;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("%lld\n", countInversions(arr, 0, n - 1));

    free(arr);
    return 0;
}

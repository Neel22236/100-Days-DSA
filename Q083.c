#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;

    // Move the boundary of the unsorted subarray one by one
    for (i = 0; i < n - 1; i++) {
        // Find the minimum element in the unsorted part
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element of the unsorted part
        if (min_idx != i) {
            temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
}

int main() {
    int n;

    // Read the size of the array
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    // Read the array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform Selection Sort
    selectionSort(arr, n);

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d%s", arr[i], (i == n - 1) ? "" : " ");
    }
    printf("\n");

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n) {
    if (n <= 0) return;

    // 1. Find the maximum element to determine the size of freq array
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }

    // 2. Build frequency array (count array) initialized to 0
    int *count = (int *)calloc(max + 1, sizeof(int));
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // 3. Compute prefix sums (cumulative count)
    // This tells us the actual position of each element in the output
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // 4. Build the output array
    int *output = (int *)malloc(n * sizeof(int));
    // Traverse backwards to maintain stability
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // 5. Copy the sorted elements back into the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    // Free allocated memory
    free(count);
    free(output);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    countingSort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d%s", arr[i], (i == n - 1) ? "" : " ");
    }
    printf("\n");

    free(arr);
    return 0;
}

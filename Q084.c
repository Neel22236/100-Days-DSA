#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    // Start from the second element (index 1)
    for (i = 1; i < n; i++) {
        key = arr[i]; // The element to be inserted
        j = i - 1;

        /* Move elements of arr[0..i-1] that are
         *          greater than key, to one position ahead
         *          of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        // Insert the key at its correct position
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d%s", arr[i], (i == n - 1) ? "" : " ");
    }
    printf("\n");

    return 0;
}

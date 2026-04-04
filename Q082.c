#include <stdio.h>

// Function to find the lower bound
int findLowerBound(int arr[], int n, int x) {
    int low = 0, high = n;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x) {
            high = mid; // Narrow search to the left half, including mid
        } else {
            low = mid + 1; // Element is smaller than x, search the right half
        }
    }
    return low;
}

// Function to find the upper bound
int findUpperBound(int arr[], int n, int x) {
    int low = 0, high = n;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > x) {
            high = mid; // Narrow search to the left half, including mid
        } else {
            low = mid + 1; // Element is less than or equal to x, search the right half
        }
    }
    return low;
}

int main() {
    int n, x;

    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (scanf("%d", &x) != 1) return 0;

    int lb = findLowerBound(arr, n, x);
    int ub = findUpperBound(arr, n, x);

    printf("%d %d\n", lb, ub);

    return 0;
}

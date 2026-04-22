#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int index;
} Element;

void merge(Element arr[], int l, int mid, int r, int count[]) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    Element *L = (Element *)malloc(n1 * sizeof(Element));
    Element *R = (Element *)malloc(n2 * sizeof(Element));

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = l;
    int rightSmallerCount = 0;

    while (i < n1 && j < n2) {
        if (L[i].value <= R[j].value) {
            // When taking from Left, add current rightSmallerCount to its index
            count[L[i].index] += rightSmallerCount;
            arr[k++] = L[i++];
        } else {
            // When taking from Right, increment the counter
            rightSmallerCount++;
            arr[k++] = R[j++];
        }
    }

    // Process remaining elements
    while (i < n1) {
        count[L[i].index] += rightSmallerCount;
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }

    free(L);
    free(R);
}

void solveMergeSort(Element arr[], int l, int r, int count[]) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        solveMergeSort(arr, l, mid, count);
        solveMergeSort(arr, mid + 1, r, count);
        merge(arr, l, mid, r, count);
    }
}

int main() {
    int nums[] = {5, 2, 6, 1};
    int n = sizeof(nums) / sizeof(nums[0]);

    Element *arr = (Element *)malloc(n * sizeof(Element));
    int *count = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        arr[i].value = nums[i];
        arr[i].index = i;
    }

    solveMergeSort(arr, 0, n - 1, count);

    printf("Count of smaller elements to the right: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", count[i]);
    }
    printf("\n");

    free(arr);
    free(count);
    return 0;
}

#include <stdio.h>

int isMinHeap(int arr[], int n) {
    for (int i = 0; i <= (n - 2) / 2; i++) {
        if (2*i + 1 < n && arr[i] > arr[2*i + 1])
            return 0;
        if (2*i + 2 < n && arr[i] > arr[2*i + 2])
            return 0;
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    if (isMinHeap(arr, n)) printf("YES\n");
    else printf("NO\n");

    return 0;
}
/*Problem: Given an array of integers, rotate the array to the right by k positions.

Input:
- First line: integer n
- Second line: n integers
- Third line: integer k*/

#include<stdio.h>
#define Max 100
void rotateRight(int n, int arr[Max], int k) {
    k = k % n; // Handle cases where k is greater than n
    int temp[Max];

    // Copy the last k elements to the temporary array
    for (int i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    }

    // Shift the remaining elements to the right
    for (int i = n - 1; i >= k; i--) {
        arr[i] = arr[i - k];
    }

    // Copy the temporary array back to the original array
    for (int i = 0; i < k; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    int n, k;
    int arr[Max];

    // Read size of array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Read elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read number of positions to rotate
    printf("Enter the number of positions to rotate: ");
    scanf("%d", &k);

    // Rotate the array to the right by k positions
    rotateRight(n, arr, k);

    // Print the rotated array
    printf("Rotated array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
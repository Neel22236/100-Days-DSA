/*Problem: Write a program to find the maximum and minimum values present in a given array of integers.

Input:
- First line: integer n
- Second line: n integers*/

#include<stdio.h>
#define Max 100
void findMaxMin(int n, int arr[Max], int *max, int *min
) {
    *max = arr[0];
    *min = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > *max) {
            *max = arr[i];
        }
        if (arr[i] < *min) {
            *min = arr[i];
        }
    }
}       

int main() {
    int n;
    int arr[Max];
    int max, min;

    // Read size of array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Read elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Find maximum and minimum values
    findMaxMin(n, arr, &max, &min);

    // Print the results
    printf("Maximum value: %d\n", max);
    printf("Minimum value: %d\n", min);

    return 0;
}
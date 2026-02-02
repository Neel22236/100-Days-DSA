/*Problem: Given an array of integers, find two elements whose sum is closest to zero.

Input:
- First line: integer n
- Second line: n space-separated integers
*/

#include<stdio.h>
#define Max 100
void findClosestToZero(int n, int arr[Max], int *num1, int *num2) {
    int closestSum = arr[0] + arr[1];
    *num1 = arr[0];
    *num2 = arr[1];

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];
            if (abs(sum) < abs(closestSum)) {
                closestSum = sum;
                *num1 = arr[i];
                *num2 = arr[j];
            }
        }
    }
}

int main() {
    int n;
    int arr[Max];
    int num1, num2;

    // Read size of array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Read elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Find two elements whose sum is closest to zero
    findClosestToZero(n, arr, &num1, &num2);

    // Print the results
    printf("Two elements whose sum is closest to zero: %d and %d\n", num1, num2);

    return 0;
}
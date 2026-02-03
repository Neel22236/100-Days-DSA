/*Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

Input:
- First line: integer n
- Second line: n integers*/

#include<stdio.h>
#define Max 100
int countZeroSumSubarrays(int n, int arr[Max]) {
    int count = 0;

    // Check all subarrays
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == 0) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    int n;
    int arr[Max];

    // Read size of array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Read elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Count the number of subarrays whose sum is equal to zero
    int result = countZeroSumSubarrays(n, arr);

    // Print the result
    printf("Number of subarrays whose sum is equal to zero: %d\n", result);

    return 0;
}

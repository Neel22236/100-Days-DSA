/*Problem: Given an array of integers, count the frequency of each distinct element and print the result.

Input:
- First line: integer n (size of array)
- Second line: n integers*/

#include<stdio.h>
#define Max 100 
void countFrequency(int n, int arr[Max]) {
    int frequency[Max] = {0}; // Initialize frequency array to 0

    // Count frequency of each element
    for (int i = 0; i < n; i++) {
        frequency[arr[i]]++;
    }

    // Print the frequency of each distinct element
    printf("Element\tFrequency\n");
    for (int i = 0; i < Max; i++) {
        if (frequency[i] > 0) {
            printf("%d\t%d\n", i, frequency[i]);
        }
    }
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

    // Count and print frequency of each distinct element
    countFrequency(n, arr);

    return 0;
}
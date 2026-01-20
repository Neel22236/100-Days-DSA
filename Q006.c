/*Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

Input:
- First line: integer n
- Second line: n space-separated integers (sorted array)*/

#include<stdio.h>
int main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter sorted elements: ");
    
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    printf("Unique elements: ");
    for(int i=0; i<n; i++){
        // Print the first element or if the current element is different from the previous one
        if(i == 0 || arr[i] != arr[i-1]){
            printf("%d ", arr[i]);
        }
    }
    printf("\n");

    return 0;
}
//Problem: Given an array of n integers, reverse the array in-place using two-pointer approach.
#include<stdio.h>
int main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter elements: ");
    
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    // Two-pointer approach to reverse the array
    int left = 0;
    int right = n - 1;

    while(left < right){
        // Swap arr[left] and arr[right]
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }

    printf("Reversed array: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;

}

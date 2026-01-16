/*Delete an Element from an Array

Problem: Write a C program to delete the element 
at a given 1-based position pos from an array of n integers. 
Shift remaining elements to the left.*/

#include<stdio.h>
int main(){
    int n,pos;
    printf("enter the number of elements: ");
    scanf("%d",&n);

    int arr[n];
    printf("the elements are: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("enter the position: ");
    scanf("%d",&pos);

    if(pos < 1 || pos > n) {
        printf("Invalid position");
        return 0;
    }

    
    for(int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    
    for(int i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

    






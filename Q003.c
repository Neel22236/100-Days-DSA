//Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.

#include<stdio.h>
#include<stdbool.h>
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d",n);

    int arr[n];
    printf("Enter elements: ");
    
    for (int i = 0; i < n; i++) {
        scanf("%d",arr[i]);
    }

    int key;
    printf("Enter the element to search: ");
    scanf("%d",key);
     
    bool found = false;

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element found at index: ");
            found = true;
            break;   // stop searching once found
        }
    }

    if (!found) {
        printf("Element not found in the array.");
    }

    return 0;
}

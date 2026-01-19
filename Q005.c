/* Problem: A system receives two separate logs of user arrival times from two different servers.
Each log is already sorted in ascending order.
Your task is to create
a single chronological log that preserves the correct order of arrivals.

Input:
- First line: integer p (number of entries in server log 1)
- Second line: p sorted integers representing arrival times from server 1
- Third line: integer q (number of entries in server log 2)
- Fourth line: q sorted integers representing arrival times from server 2)
*/

#include<stdio.h>
int main(){
    int p, q;
    printf("Enter number of entries in server log 1: ");    
    scanf("%d",&p);
    int log1[p];
    printf("Enter arrival times from server 1: ");
    for(int i=0; i<p; i++){
        scanf("%d",&log1[i]);
    }

    printf("Enter number of entries in server log 2: ");
    scanf("%d",&q);
    int log2[q];
    printf("Enter arrival times from server 2: ");
    for(int i=0; i<q; i++){
        scanf("%d",&log2[i]);
    }

    // Merge the two sorted logs
    int merged[p+q];
    int i = 0, j = 0, k = 0;
    while(i < p && j < q){
        if(log1[i] < log2[j]){
            merged[k++] = log1[i++];
        } else {
            merged[k++] = log2[j++];
        }
    }
    while(i < p){
        merged[k++] = log1[i++];
    }
    while(j < q){
        merged[k++] = log2[j++];
    }
    printf("Merged chronological log: ");
    for(int i=0; i<p+q; i++){
        printf("%d ", merged[i]);
    }



    return 0;
}
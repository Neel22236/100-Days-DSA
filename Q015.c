/*Problem: Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.

Input:
- First line: two integers m and n
- Next m lines: n integers each*/

#include<stdio.h>
#define Max 100
int sumPrimaryDiagonal(int m, int n, int matrix[Max][Max]) {
    int sum = 0;
    for (int i = 0; i < m && i < n; i++) {
        sum += matrix[i][i];
    }
    return sum;
}

int main(){
    int m,n;
    int matrix[Max][Max];

    // Read dimensions
    printf("enter the number of rows and coloumns: ");
    scanf("%d %d",&m,&n);

    // Read matrix
    printf("enter the elements of the matrix:\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&matrix[i][j]);
            
        }
    }

    // Calculate sum of primary diagonal
    int sum = sumPrimaryDiagonal(m, n, matrix);
    printf("The sum of the primary diagonal elements is: %d\n", sum);
    
    return 0;
}
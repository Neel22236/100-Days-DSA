/*Problem: Write a program to check whether a given matrix is symmetric. A matrix is said to be symmetric if it is a square matrix and is equal to its transpose (i.e., element at position [i][j] is equal to element at position [j][i] for all valid i and j).

Input:
- First line: two integers m and n representing the number of rows and columns
- Next m lines: n integers each representing the elements of the matrix*/

#include<stdio.h>
#define Max 100
int isSymmetric(int m, int n, int matrix[Max][Max]) {
    if (m != n) {
        return 0; // Not a square matrix
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return 0; // Not symmetric
            }
        }
    }
    return 1; // Symmetric
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

    // Check if matrix is symmetric
    if (isSymmetric(m, n, matrix)) {
        printf("The matrix is symmetric.\n");
    } else {
        printf("The matrix is not symmetric.\n");
    }
    return 0;
}
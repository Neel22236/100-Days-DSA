/*Problem: Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.

Input:
- First line: integer n representing number of rows and columns
- Next n lines: n integers each representing the matrix elements
*/

#include<stdio.h>
#define Max 100
int isIdentity(int n, int matrix[Max][Max]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j && matrix[i][j] != 1) {
                return 0; // Diagonal element is not 1
            } else if (i != j && matrix[i][j] != 0) {
                return 0; // Non-diagonal element is not 0
            }
        }
    }
    return 1; // Identity matrix
}

int main(){
    int n;
    int matrix[Max][Max];

    // Read dimensions
    printf("enter the number of rows and coloumns: ");
    scanf("%d",&n);

    // Read matrix
    printf("enter the elements of the matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&matrix[i][j]);
            
        }
    }

    // Check if matrix is identity
    if (isIdentity(n, matrix)) {
        printf("The matrix is an Identity Matrix.\n");
    } else {
        printf("The matrix is not an Identity Matrix.\n");
    }
    return 0;
}
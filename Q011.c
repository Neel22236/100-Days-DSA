/*Problem: Write a program to perform addition of two matrices having the same dimensions. The sum of two matrices is obtained by adding corresponding elements of the matrices.

Input:
- First line: two integers m and n representing the number of rows and columns
- Next m lines: n integers each representing the elements of the first matrix
- Next m lines: n integers each representing the elements of the second matrix*/

#include <stdio.h>
#define MAX 100
void addMatrices(int m, int n, int matrixA[MAX][MAX], int matrixB[MAX][MAX], int result[MAX][MAX]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

int main() {
    int m, n;
    int matrixA[MAX][MAX], matrixB[MAX][MAX], result[MAX][MAX];

    // Read dimensions
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);

    // Read first matrix
    printf("Enter the elements of the first matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrixA[i][j]);
        }
    }

    // Read second matrix
    printf("Enter the elements of the second matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrixB[i][j]);
        }
    }

    // Add matrices
    addMatrices(m, n, matrixA, matrixB, result);

    // Print result
    printf("Result of addition:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
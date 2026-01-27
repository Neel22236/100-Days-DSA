/*Problem: You are given a rectangular matrix of integers. Starting from the outer boundary, traverse the matrix in a clockwise manner and continue moving inward layer by layer until all elements are visited.

Input:
- First line: two integers r and c representing the number of rows and columns
- Next r lines: c integers each representing the matrix elements*/

#include<stdio.h>
#define Max 100
void spiralTraverse(int r, int c, int matrix[Max][Max]){
    int top = 0, bottom = r-1, left = 0, rigth = c-1;
    while (top <=bottom && left <=rigth){
        //traverse from left to right
        for(int i=left; i<=rigth; i++)  
            printf("%d ", matrix[top][i]);
        top++;
        //traverse from top to bottom
        for(int i=top; i<=bottom; i++)
            printf("%d ", matrix[i][rigth]);
        rigth--;
        //traverse from right to left
        if(top <= bottom){
            for(int i=rigth; i>=left; i--)
                printf("%d ", matrix[bottom][i]);
            bottom--;
        }
        //traverse from bottom to top
        if(left <= rigth){
            for(int i=bottom; i>=top; i--)
                printf("%d ", matrix[i][left]);
            left++;
        }
    }
}

int main(){
    int r,c;
    int matrix[Max][Max];
    // Read dimensions
    printf("enter the number of rows and coloumns: ");
    scanf("%d %d",&r,&c);   
    // Read matrix
    printf("enter the elements of the matrix:\n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    // Traverse the matrix in spiral order
    printf("Spiral order traversal of the matrix is:\n");
    spiralTraverse(r, c, matrix);
    return 0;
    
}
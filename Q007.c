/*Problem: Write a recursive function fib(n)
to compute the n-th Fibonacci number where fib(0)=0 and fib(1)=1.
*/

#include<stdio.h>
int fib(int n) {
    if (n == 0) {
        return 0; // Base case: fib(0) = 0
    } else if (n == 1) {
        return 1; // Base case: fib(1) = 1
    } else {
        return fib(n - 1) + fib(n - 2); // Recursive case
    }
}
int main() {
    int n;
    printf("Enter the Fibonacci index: ");
    scanf("%d", &n);

    int result = fib(n);
    printf("The %d-th Fibonacci number is: %d\n", n, result);

    return 0;
}
/*Problem: Given integers a and b, compute a^b using recursion without using pow() function.*/

#include<stdio.h>
int power(int a, int b) {
    if (b == 0) {
        return 1; // Base case: a^0 = 1
    } else if (b > 0) {
        return a * power(a, b - 1); // Recursive case for positive exponent
    } else {
        return 1 / power(a, -b); // Recursive case for negative exponent
    }
}
int main() {
    int a, b;
    printf("Enter base (a) and exponent (b): ");
    scanf("%d %d", &a, &b);

    int result = power(a, b);
    printf("%d raised to the power of %d is: %d\n", a, b, result);

    return 0;
}
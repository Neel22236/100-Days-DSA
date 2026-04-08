#include <stdio.h>

long long findIntegerSquareRoot(long long n) {
    // Base cases: square root of 0 is 0, 1 is 1
    if (n < 2) return n;

    long long low = 0, high = n;
    long long ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        // Calculate square of mid
        long long square = mid * mid;

        if (square == n) {
            // Exact square root found
            return mid;
        } else if (square < n) {
            // mid is a potential answer, but there might be a
            // larger one to the right
            ans = mid;
            low = mid + 1;
        } else {
            // mid*mid is too large, search the left half
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    long long n;

    // Read input
    if (scanf("%lld", &n) != 1) return 0;

    // Calculate and print the integer square root
    printf("%lld\n", findIntegerSquareRoot(n));

    return 0;
}

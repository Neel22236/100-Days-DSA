#include <stdio.h>

// Function to check if an allocation is possible for a given 'maxPages'
int isPossible(int books[], int n, int m, int maxPages) {
    int studentsRequired = 1;
    int currentSum = 0;

    for (int i = 0; i < n; i++) {
        // If a single book has more pages than maxPages, it's impossible
        if (books[i] > maxPages) return 0;

        if (currentSum + books[i] <= maxPages) {
            currentSum += books[i];
        } else {
            // Allocate to the next student
            studentsRequired++;
            currentSum = books[i];

            // If more students are needed than available, return false
            if (studentsRequired > m) return 0;
        }
    }
    return 1;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    int books[n];
    int sum = 0, maxVal = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &books[i]);
        sum += books[i];
        if (books[i] > maxVal) maxVal = books[i];
    }

    // If there are more students than books, allocation is impossible
    // (given every student must get at least one book)
    if (m > n) {
        printf("-1\n");
        return 0;
    }

    // Binary Search Range
    // low: The maximum single book (at least one student must carry it)
    // high: The sum of all books (one student carries everything)
    int low = maxVal, high = sum;
    int result = sum;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(books, n, m, mid)) {
            result = mid;    // This max value works, try to find a smaller one
            high = mid - 1;
        } else {
            low = mid + 1;   // Not possible, we need to increase the limit
        }
    }

    printf("%d\n", result);

    return 0;
}

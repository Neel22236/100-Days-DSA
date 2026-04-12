#include <stdio.h>

// Function to check if all boards can be painted in 'maxTime'
int isPossible(int boards[], int n, int k, int maxTime) {
    int paintersCount = 1;
    int currentTimeSpent = 0;

    for (int i = 0; i < n; i++) {
        // If a single board is longer than maxTime, it's impossible
        if (boards[i] > maxTime) return 0;

        if (currentTimeSpent + boards[i] <= maxTime) {
            currentTimeSpent += boards[i];
        } else {
            // Assign the current board to a new painter
            paintersCount++;
            currentTimeSpent = boards[i];

            // If we need more painters than available, return false
            if (paintersCount > k) return 0;
        }
    }
    return 1;
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;

    int boards[n];
    long long totalLength = 0;
    int maxBoard = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
        totalLength += boards[i];
        if (boards[i] > maxBoard) {
            maxBoard = boards[i];
        }
    }

    // Binary Search Range
    // low: The longest single board (cannot be split)
    // high: The sum of all boards (one painter does everything)
    long long low = maxBoard;
    long long high = totalLength;
    long long result = totalLength;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (isPossible(boards, n, k, (int)mid)) {
            result = mid;      // This time is achievable, try to find a smaller one
            high = mid - 1;
        } else {
            low = mid + 1;     // Not enough time, increase the limit
        }
    }

    printf("%lld\n", result);

    return 0;
}

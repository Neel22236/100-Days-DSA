#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Comparison function for qsort to sort strings lexicographically
int compareStrings(const void *a, const void *b) {
    return strcmp((char *)a, (char *)b);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    // Array to store up to n names, each max 100 chars
    char names[n][101];

    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    // Sort names alphabetically
    qsort(names, n, sizeof(names[0]), compareStrings);

    char winner[101];
    int max_votes = 0;

    int current_votes = 1;
    strcpy(winner, names[0]); // Initialize winner with the first candidate

    for (int i = 1; i <= n; i++) {
        // If the current name is the same as the previous one, increment count
        if (i < n && strcmp(names[i], names[i - 1]) == 0) {
            current_votes++;
        } else {
            // If we found a candidate with strictly MORE votes, update the winner
            // Because the list is sorted, if votes are tied, the first one
            // encountered remains the winner (satisfying lexicographical smallest)
            if (current_votes > max_votes) {
                max_votes = current_votes;
                strcpy(winner, names[i - 1]);
            }
            current_votes = 1; // Reset count for the next unique name
        }
    }

    printf("%s %d\n", winner, max_votes);

    return 0;
}

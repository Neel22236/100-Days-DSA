#include <stdio.h>
#include <stdlib.h>

// Structure for Hash Map Entry
typedef struct {
    int sum;
    int index;
} Entry;

// Function to find the longest subarray with 0 sum
int maxLen(int arr[], int n) {
    // Hash table to store the first occurrence of each prefix sum
    // Size is 2*n to reduce collisions
    int tableSize = 2 * n;
    Entry* hashTable = (Entry*)malloc(tableSize * sizeof(Entry));

    // Initialize hash table with a value representing "empty"
    for (int i = 0; i < tableSize; i++) {
        hashTable[i].sum = -1e9; // Using a very small number as a flag
    }

    int prefixSum = 0;
    int max_len = 0;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // Case 1: If current prefix sum is 0, the subarray is from index 0 to i
        if (prefixSum == 0) {
            max_len = i + 1;
        }

        // Case 2: Check if this prefixSum has been seen before
        int hash = abs(prefixSum) % tableSize;
        while (hashTable[hash].sum != -1e9 && hashTable[hash].sum != prefixSum) {
            hash = (hash + 1) % tableSize;
        }

        if (hashTable[hash].sum == prefixSum) {
            // Seen before! Calculate length and update max_len
            int current_len = i - hashTable[hash].index;
            if (current_len > max_len) {
                max_len = current_len;
            }
        } else {
            // Not seen before, store the first occurrence index
            hashTable[hash].sum = prefixSum;
            hashTable[hash].index = i;
        }
    }

    free(hashTable);
    return max_len;
}

int main() {
    int n;
    // Reading size based on input flow
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", maxLen(arr, n));

    return 0;
}

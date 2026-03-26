#include <stdio.h>
#include <string.h>

char firstNonRepeating(char* s) {
    int freq[26] = {0};
    int n = strlen(s);

    // Pass 1: Count the frequency of each character
    for (int i = 0; i < n; i++) {
        freq[s[i] - 'a']++;
    }

    // Pass 2: Find the first character with frequency 1
    for (int i = 0; i < n; i++) {
        if (freq[s[i] - 'a'] == 1) {
            return s[i];
        }
    }

    // Return '$' if no non-repeating character exists
    return '$';
}

int main() {
    char s[100000]; // Assuming a reasonable maximum length

    if (scanf("%s", s) == 1) {
        char result = firstNonRepeating(s);
        printf("%c\n", result);
    }

    return 0;
}

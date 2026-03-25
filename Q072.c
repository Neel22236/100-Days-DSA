#include <stdio.h>
#include <string.h>

char findFirstRepeated(char* s) {
    // Array to store the occurrence of characters 'a' through 'z'
    // Initialized to 0 (false)
    int seen[26] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        // Map the character to an index (0-25)
        int index = s[i] - 'a';

        // If the character has been seen before, this is its second occurrence
        if (seen[index] == 1) {
            return s[i];
        }

        // Mark the character as seen
        seen[index] = 1;
    }

    // Return a special value if no character is repeated
    return '\0';
}

int main() {
    char s[1000];

    // Input the string
    if (scanf("%s", s) == 1) {
        char result = findFirstRepeated(s);

        if (result != '\0') {
            printf("%c\n", result);
        } else {
            printf("-1\n");
        }
    }

    return 0;
}

#include <stdio.h>
#include <string.h>

#define EMPTY -1

int hash(int key, int m) {
    return key % m;
}

void insert(int table[], int m, int key) {
    int h = hash(key, m);

    for (int i = 0; i < m; i++) {
        int idx = (h + i*i) % m;

        if (table[idx] == EMPTY) {
            table[idx] = key;
            return;
        }
    }
}

int search(int table[], int m, int key) {
    int h = hash(key, m);

    for (int i = 0; i < m; i++) {
        int idx = (h + i*i) % m;

        if (table[idx] == EMPTY)
            return 0;

        if (table[idx] == key)
            return 1;
    }
    return 0;
}

int main() {
    int m, q;
    scanf("%d", &m);
    scanf("%d", &q);

    int table[m];
    for (int i = 0; i < m; i++) table[i] = EMPTY;

    while (q--) {
        char op[10];
        int key;
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(table, m, key);
        } else if (strcmp(op, "SEARCH") == 0) {
            if (search(table, m, key))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}
#include <stdio.h>
#include <string.h>

#define MAX 100000

int main() {
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    int pq[MAX];
    int size = 0;

    for (int i = 0; i < n; i++) {
        char op[10];
        scanf("%s", op);
        
        if (strcmp(op, "insert") == 0) {
            int val;
            scanf("%d", &val);
            pq[size++] = val;
        } else if (strcmp(op, "delete") == 0) {
            if (size == 0) {
                printf("-1\n");
            } else {
                int min_idx = 0;
                for (int j = 1; j < size; j++) {
                    if (pq[j] < pq[min_idx]) {
                        min_idx = j;
                    }
                }
                printf("%d\n", pq[min_idx]);
                for (int j = min_idx; j < size - 1; j++) {
                    pq[j] = pq[j + 1];
                }
                size--;
            }
        } else if (strcmp(op, "peek") == 0) {
            if (size == 0) {
                printf("-1\n");
            } else {
                int min_idx = 0;
                for (int j = 1; j < size; j++) {
                    if (pq[j] < pq[min_idx]) {
                        min_idx = j;
                    }
                }
                printf("%d\n", pq[min_idx]);
            }
        }
    }

    return 0;
}
#include <stdio.h>

#define MAX 10000

int main() {
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    int stack[MAX];
    int top = -1;

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        if (top < MAX - 1) {
            stack[++top] = val;
        }
    }

    int m;
    if (scanf("%d", &m) == 1) {
        for (int i = 0; i < m; i++) {
            if (top >= 0) {
                top--;
            }
        }
    }

    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");

    return 0;
}
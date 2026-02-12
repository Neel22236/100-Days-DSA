#include <stdio.h>

#define MAX 10000

int main() {
    int stack[MAX];
    int top = -1;
    int n;

    if (scanf("%d", &n) != 1) {
        return 0;
    }

    while (n--) {
        int op;
        scanf("%d", &op);

        if (op == 1) {
            int val;
            scanf("%d", &val);
            if (top < MAX - 1) {
                stack[++top] = val;
            }
        } else if (op == 2) {
            if (top < 0) {
                printf("Stack Underflow\n");
            } else {
                printf("%d\n", stack[top--]);
            }
        } else if (op == 3) {
            for (int i = top; i >= 0; i--) {
                printf("%d ", stack[i]);
            }
            printf("\n");
        }
    }

    return 0;
}
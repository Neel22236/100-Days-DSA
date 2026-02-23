#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 0;
    }

    int* queue = (int*)malloc(n * sizeof(int));
    int* stack = (int*)malloc(n * sizeof(int));

    int front = 0, rear = 0;
    int top = -1;

    for (int i = 0; i < n; i++) {
        scanf("%d", &queue[rear++]);
    }

    while (front < rear) {
        stack[++top] = queue[front++];
    }

    front = 0;
    rear = 0;

    while (top >= 0) {
        queue[rear++] = stack[top--];
    }

    for (int i = front; i < rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");

    free(queue);
    free(stack);

    return 0;
}
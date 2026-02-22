#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    struct Node *front = NULL, *rear = NULL;

    for (int i = 0; i < n; i++) {
        char op[15];
        scanf("%14s", op);

        if (strcmp(op, "enqueue") == 0 || strcmp(op, "1") == 0) {
            int val;
            scanf("%d", &val);
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = val;
            newNode->next = NULL;
            
            if (rear == NULL) {
                front = rear = newNode;
            } else {
                rear->next = newNode;
                rear = newNode;
            }
        } else if (strcmp(op, "dequeue") == 0 || strcmp(op, "2") == 0) {
            if (front == NULL) {
                printf("-1\n");
            } else {
                struct Node* temp = front;
                printf("%d\n", temp->data);
                front = front->next;
                
                if (front == NULL) {
                    rear = NULL;
                }
                free(temp);
            }
        }
    }

    return 0;
}
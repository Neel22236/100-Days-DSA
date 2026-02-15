#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (top == NULL) return 0;
    struct Node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int main() {
    char token[100];
    while (scanf("%99s", token) == 1) {
        if ((token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/') && token[1] == '\0') {
            int val1 = pop();
            int val2 = pop();
            int res = 0;
            if (token[0] == '+') {
                res = val2 + val1;
            } else if (token[0] == '-') {
                res = val2 - val1;
            } else if (token[0] == '*') {
                res = val2 * val1;
            } else if (token[0] == '/') {
                res = val1 != 0 ? val2 / val1 : 0;
            }
            push(res);
        } else {
            push(atoi(token));
        }
    }
    printf("%d\n", pop());
    return 0;
}
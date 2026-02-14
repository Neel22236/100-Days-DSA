#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 1000

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int main() {
    char infix[MAX];
    if (scanf("%999s", infix) != 1) {
        return 0;
    }

    char stack[MAX];
    int top = -1;
    char postfix[MAX];
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isalnum(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            stack[++top] = c;
        } else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            if (top != -1 && stack[top] == '(') {
                top--;
            }
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                if (c == '^' && stack[top] == '^') {
                    break;
                }
                postfix[j++] = stack[top--];
            }
            stack[++top] = c;
        }
    }

    while (top != -1) {
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';

    printf("%s\n", postfix);

    return 0;
}
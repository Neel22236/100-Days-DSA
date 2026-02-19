#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

int main() {
    char op[20];
    Node* head = NULL;
    Node* tail = NULL;
    int size = 0;

    int first_token = 1;
    while (scanf("%19s", op) == 1) {
        if (first_token && isdigit(op[0])) {
            first_token = 0;
            continue;
        }
        first_token = 0;

        if (strcmp(op, "push_front") == 0) {
            int val;
            if (scanf("%d", &val) != 1) break;
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->data = val;
            newNode->prev = NULL;
            newNode->next = head;
            if (head == NULL) tail = newNode;
            else head->prev = newNode;
            head = newNode;
            size++;
        } else if (strcmp(op, "push_back") == 0) {
            int val;
            if (scanf("%d", &val) != 1) break;
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->data = val;
            newNode->next = NULL;
            newNode->prev = tail;
            if (tail == NULL) head = newNode;
            else tail->next = newNode;
            tail = newNode;
            size++;
        } else if (strcmp(op, "pop_front") == 0) {
            if (head == NULL) {
                printf("-1\n");
            } else {
                Node* temp = head;
                printf("%d\n", temp->data);
                head = head->next;
                if (head == NULL) tail = NULL;
                else head->prev = NULL;
                free(temp);
                size--;
            }
        } else if (strcmp(op, "pop_back") == 0) {
            if (tail == NULL) {
                printf("-1\n");
            } else {
                Node* temp = tail;
                printf("%d\n", temp->data);
                tail = tail->prev;
                if (tail == NULL) head = NULL;
                else tail->next = NULL;
                free(temp);
                size--;
            }
        } else if (strcmp(op, "front") == 0) {
            if (head == NULL) printf("-1\n");
            else printf("%d\n", head->data);
        } else if (strcmp(op, "back") == 0) {
            if (tail == NULL) printf("-1\n");
            else printf("%d\n", tail->data);
        } else if (strcmp(op, "empty") == 0) {
            printf("%s\n", size == 0 ? "true" : "false");
        } else if (strcmp(op, "size") == 0) {
            printf("%d\n", size);
        } else if (strcmp(op, "clear") == 0) {
            while (head != NULL) {
                Node* temp = head;
                head = head->next;
                free(temp);
            }
            tail = NULL;
            size = 0;
        }
    }
    return 0;
}
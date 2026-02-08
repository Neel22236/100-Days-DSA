/*Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of nodes)
- Second line: n space-separated integers (linked list elements)
- Third line: integer key (element to be counted)*/

#include <stdio.h>
#include <stdlib.h>
// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to count occurrences of a key in the linked list
int countOccurrences(struct Node* head, int key) {
    int count = 0;
    struct Node* current = head;

    // Traverse the list and count occurrences of the key
    while (current != NULL) {
        if (current->data == key) {
            count++;
        }
        current = current->next;
    }
    return count; // Return the count of occurrences
}

// Function to free the linked list memory
void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    int n, key;
    struct Node* head = NULL;
    struct Node* tail = NULL;

    // Read the number of nodes
    scanf("%d", &n);

    // Read the linked list elements
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        struct Node* newNode = createNode(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Read the key to be counted
    scanf("%d", &key);

    // Count occurrences of the key in the linked list
    int occurrences = countOccurrences(head, key);
    printf("%d\n", occurrences); // Print the count of occurrences

    // Free the linked list memory
    freeList(head);
    
    return 0;
}

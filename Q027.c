/*Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers*/

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the end of the doubly linked list
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode; // If the list is empty, the new node becomes the head
    }
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next; // Traverse to the end of the list
    }
    current->next = newNode; // Link the last node to the new node
    newNode->prev = current; // Link the new node back to the last node
    return head; // Return the head of the list
}

// Function to traverse the list and print the elements
void traverseList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next; // Move to the next node
    }
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
    int n;
    struct Node* head = NULL;

    // Read the number of nodes
    scanf("%d", &n);

    // Read the linked list elements and insert them into the list
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        head = insertEnd(head, data); // Insert each element at the end of the list
    }

    // Traverse and print the list
    traverseList(head);
    printf("\n");

    // Free the allocated memory for the list
    freeList(head);
    return 0;
}



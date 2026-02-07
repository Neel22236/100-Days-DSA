/*Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key
*/

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

// Function to delete the first occurrence of a key in the linked list

struct Node* deleteFirstOccurrence(struct Node* head, int key) {
    struct Node* current = head;
    struct Node* previous = NULL;

    // Traverse the list to find the key
    while (current != NULL) {
        if (current->data == key) {
            // If the node to be deleted is the head
            if (previous == NULL) {
                head = current->next; // Update head
            } else {
                previous->next = current->next; // Bypass the current node
            }
            free(current); // Free the memory of the deleted node
            return head; // Return the updated head
        }
        previous = current;
        current = current->next;
    }
    return head; // Return the original head if key not found
}
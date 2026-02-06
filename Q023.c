/*Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)
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

// Function to merge two sorted linked lists
struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
    // Create a dummy node to help with merging
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    // Merge the two lists
    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    // If there are remaining nodes in either list, append them
    if (list1 != NULL) {
        tail->next = list1;
    } else {
        tail->next = list2;
    }

    return dummy.next; // Return the head of the merged list
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int n, m;
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    struct Node* tail1 = NULL;
    struct Node* tail2 = NULL;

    // Read the first list
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        struct Node* newNode = createNode(data);
        if (list1 == NULL) {
            list1 = newNode;
            tail1 = newNode;
        } else {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }

    // Read the second list
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int data;
        scanf("%d", &data);
        struct Node* newNode = createNode(data);
        if (list2 == NULL) {
            list2 = newNode;
            tail2 = newNode;
        } else {
            tail2->next = newNode;
            tail2 = newNode;
        }
    }

    // Merge the two sorted lists
    struct Node* mergedList = mergeSortedLists(list1, list2);

    // Print the merged list
    printList(mergedList);

    return 0;
}
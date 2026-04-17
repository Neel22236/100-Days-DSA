#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list in each bucket
struct Node {
    float data;
    struct Node* next;
};

// Function to insert a node into a bucket in sorted order (Insertion Sort)
struct Node* sortedInsert(struct Node* head, float value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // Insert at head or empty list
    if (head == NULL || head->data >= value) {
        newNode->next = head;
        return newNode;
    }

    // Locate the node before the point of insertion
    struct Node* current = head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;

    return head;
}

void bucketSort(float arr[], int n) {
    // 1. Create n empty buckets
    struct Node** buckets = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++) {
        buckets[i] = NULL;
    }

    // 2. Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)(n * arr[i]); // Index = n * value
        buckets[bucketIndex] = sortedInsert(buckets[bucketIndex], arr[i]);
    }

    // 3. Concatenate all buckets back into arr[]
    int index = 0;
    for (int i = 0; i < n; i++) {
        struct Node* current = buckets[i];
        while (current != NULL) {
            arr[index++] = current->data;
            struct Node* temp = current;
            current = current->next;
            free(temp); // Clean up memory
        }
    }
    free(buckets);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    float* arr = (float*)malloc(n * sizeof(float));
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    bucketSort(arr, n);

    // Print output
    for (int i = 0; i < n; i++) {
        printf("%.4f%s", arr[i], (i == n - 1) ? "" : " ");
    }
    printf("\n");

    free(arr);
    return 0;
}

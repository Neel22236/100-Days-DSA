#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    struct ListNode dummy;
    dummy.next = NULL;
    
    struct ListNode* temp = &dummy;
    int carry = 0;
    
    while (l1 != NULL || l2 != NULL || carry != 0) {
        
        int sum = carry;
        
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        
        carry = sum / 10;
        
        struct ListNode* newNode = createNode(sum % 10);
        
        temp->next = newNode;
        temp = temp->next;
    }
    
    return dummy.next;
}

void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // First number: 342 (2 -> 4 -> 3)
    struct ListNode* l1 = createNode(2);
    l1->next = createNode(4);
    l1->next->next = createNode(3);

    // Second number: 465 (5 -> 6 -> 4)
    struct ListNode* l2 = createNode(5);
    l2->next = createNode(6);
    l2->next->next = createNode(4);

    struct ListNode* result = addTwoNumbers(l1, l2);

    printList(result);   // Output: 7 0 8

    return 0;
}
/*Problem: Create and Traverse Singly Linked List

Input:
- First line: integer n
- Second line: n space-separated integers*/

#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* next;  
};

struct Node *head = NULL;

void create(int t){
    struct Node *n = (struct Node*)malloc(sizeof (struct Node));
    n->data = t;
    n->next = head;
    head = n;
}
void display(){

    struct Node *p = head;

    while(p!=NULL){
        printf("element= %d \n" ,p->data);
        p = p->next;
    }
    
}

int main(){

   create(3);
   create(5);
   display();
    

    return 0;
}



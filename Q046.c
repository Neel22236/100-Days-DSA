#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int val) {
    if (val == -1) return NULL;
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void levelOrder(struct TreeNode* root, int n) {
    if (root == NULL) return;

    struct TreeNode** queue = (struct TreeNode**)malloc(n * sizeof(struct TreeNode*));
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct TreeNode* curr = queue[front++];
        printf("%d ", curr->val);

        if (curr->left != NULL) {
            queue[rear++] = curr->left;
        }
        if (curr->right != NULL) {
            queue[rear++] = curr->right;
        }
    }
    free(queue);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    if (arr[0] == -1) {
        free(arr);
        return 0;
    }

    struct TreeNode** buildQueue = (struct TreeNode**)malloc(n * sizeof(struct TreeNode*));
    int bFront = 0, bRear = 0;

    struct TreeNode* root = createNode(arr[0]);
    buildQueue[bRear++] = root;

    int i = 1;
    while (i < n && bFront < bRear) {
        struct TreeNode* curr = buildQueue[bFront++];

        if (i < n && arr[i] != -1) {
            curr->left = createNode(arr[i]);
            buildQueue[bRear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            buildQueue[bRear++] = curr->right;
        }
        i++;
    }

    levelOrder(root, n);
    printf("\n");

    free(arr);
    free(buildQueue);
    return 0;
}
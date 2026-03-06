#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct Pair {
    struct TreeNode* node;
    int hd;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct TreeNode** queue = (struct TreeNode**)malloc(n * sizeof(struct TreeNode*));
    int front = 0, rear = 0;

    struct TreeNode* root = createNode(arr[0]);
    queue[rear++] = root;

    int i = 1;
    while (i < n) {
        struct TreeNode* curr = queue[front++];

        if (arr[i] != -1) {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    free(queue);
    return root;
}

void verticalOrder(struct TreeNode* root) {
    if (!root)
        return;

    struct Pair* queue = (struct Pair*)malloc(1000 * sizeof(struct Pair));
    int front = 0, rear = 0;

    int map[2000][100];
    int count[2000] = {0};
    int offset = 1000;

    queue[rear++] = (struct Pair){root, 0};

    int min = 0, max = 0;

    while (front < rear) {
        struct Pair curr = queue[front++];

        int hd = curr.hd + offset;
        map[hd][count[hd]++] = curr.node->val;

        if (curr.hd < min) min = curr.hd;
        if (curr.hd > max) max = curr.hd;

        if (curr.node->left)
            queue[rear++] = (struct Pair){curr.node->left, curr.hd - 1};
        if (curr.node->right)
            queue[rear++] = (struct Pair){curr.node->right, curr.hd + 1};
    }

    for (int i = min; i <= max; i++) {
        int idx = i + offset;
        for (int j = 0; j < count[idx]; j++) {
            printf("%d", map[idx][j]);
            if (j < count[idx] - 1)
                printf(" ");
        }
        printf("\n");
    }

    free(queue);
}

int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct TreeNode* root = buildTree(arr, n);
    verticalOrder(root);

    free(arr);
    return 0;
}
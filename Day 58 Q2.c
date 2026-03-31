#include <stdio.h>
#include <stdlib.h>

// Tree Node
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Create new node
TreeNode* createNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Map for inorder index
int map[6001]; // supports values from -3000 to 3000

// Build tree function
TreeNode* build(int preorder[], int inorder[],
                int start, int end, int* preIndex) {

    if (start > end)
        return NULL;

    int rootVal = preorder[*preIndex];
    (*preIndex)++;

    TreeNode* root = createNode(rootVal);

    int pos = map[rootVal + 3000];

    root->left = build(preorder, inorder, start, pos - 1, preIndex);
    root->right = build(preorder, inorder, pos + 1, end, preIndex);

    return root;
}

// Main build function
TreeNode* buildTree(int preorder[], int inorder[], int n) {

    // Fill map
    for (int i = 0; i < n; i++) {
        map[inorder[i] + 3000] = i;
    }

    int preIndex = 0;

    return build(preorder, inorder, 0, n - 1, &preIndex);
}

// Queue for level order printing
typedef struct {
    TreeNode* arr[3000];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = -1;
}

int isEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, TreeNode* node) {
    if (q->rear == 2999) return;
    if (q->front == -1) q->front = 0;
    q->arr[++q->rear] = node;
}

TreeNode* dequeue(Queue* q) {
    if (isEmpty(q)) return NULL;
    TreeNode* temp = q->arr[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return temp;
}

// Print level order (LeetCode style)
void printLevelOrder(TreeNode* root) {
    if (root == NULL) {
        printf("[]");
        return;
    }

    Queue q;
    initQueue(&q);
    enqueue(&q, root);

    printf("[");
    while (!isEmpty(&q)) {
        TreeNode* curr = dequeue(&q);

        if (curr) {
            printf("%d", curr->val);
            enqueue(&q, curr->left);
            enqueue(&q, curr->right);
        } else {
            printf("null");
        }

        if (!isEmpty(&q)) printf(",");
    }
    printf("]");
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    TreeNode* root = buildTree(preorder, inorder, n);

    printLevelOrder(root);

    return 0;
}
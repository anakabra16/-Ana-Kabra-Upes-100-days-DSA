#include <stdio.h>
#include <stdlib.h>

// Tree Node
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Create node
TreeNode* createNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Map for inorder index
int map[6001]; // handles values from -3000 to 3000

// Build tree
TreeNode* build(int inorder[], int postorder[],
                int start, int end, int* postIndex) {

    if (start > end)
        return NULL;

    // Root from postorder
    int rootVal = postorder[*postIndex];
    (*postIndex)--;

    TreeNode* root = createNode(rootVal);

    // Find position in inorder
    int pos = map[rootVal + 3000];

    // IMPORTANT: build right first
    root->right = build(inorder, postorder, pos + 1, end, postIndex);
    root->left  = build(inorder, postorder, start, pos - 1, postIndex);

    return root;
}

// Main build function
TreeNode* buildTree(int inorder[], int postorder[], int n) {

    // Fill map
    for (int i = 0; i < n; i++) {
        map[inorder[i] + 3000] = i;
    }

    int postIndex = n - 1;

    return build(inorder, postorder, 0, n - 1, &postIndex);
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

// Print level order (LeetCode format)
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

    int inorder[n], postorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    TreeNode* root = buildTree(inorder, postorder, n);

    printLevelOrder(root);

    return 0;
}
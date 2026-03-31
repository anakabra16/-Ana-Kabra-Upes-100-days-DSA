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

// Queue for level order construction
typedef struct {
    TreeNode* arr[100];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = -1;
}

int isEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, TreeNode* node) {
    if (q->rear == 99) return;
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

// Build tree from level order (-1 = NULL)
TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    Queue q;
    initQueue(&q);

    TreeNode* root = createNode(arr[0]);
    enqueue(&q, root);

    int i = 1;
    while (i < n) {
        TreeNode* curr = dequeue(&q);

        // Left child
        if (arr[i] != -1) {
            curr->left = createNode(arr[i]);
            enqueue(&q, curr->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            enqueue(&q, curr->right);
        }
        i++;
    }

    return root;
}

// Flatten function (O(1) space)
void flatten(TreeNode* root) {
    TreeNode* curr = root;

    while (curr != NULL) {
        if (curr->left != NULL) {

            // Find rightmost node of left subtree
            TreeNode* temp = curr->left;
            while (temp->right != NULL) {
                temp = temp->right;
            }

            // Attach right subtree
            temp->right = curr->right;

            // Move left subtree to right
            curr->right = curr->left;
            curr->left = NULL;
        }

        curr = curr->right;
    }
}

// Print flattened list
void printList(TreeNode* root) {
    TreeNode* curr = root;
    while (curr != NULL) {
        printf("%d ", curr->val);
        curr = curr->right;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    TreeNode* root = buildTree(arr, n);

    flatten(root);

    printList(root);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

// Tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Create node
Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Search in inorder
int search(int inorder[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

// Build tree
Node* buildTree(int inorder[], int postorder[],
                int start, int end, int* postIndex) {

    if (start > end)
        return NULL;

    // Pick root from postorder
    int curr = postorder[*postIndex];
    (*postIndex)--;

    Node* root = createNode(curr);

    // If leaf node
    if (start == end)
        return root;

    // Find position in inorder
    int pos = search(inorder, start, end, curr);

    // IMPORTANT: build right first
    root->right = buildTree(inorder, postorder, pos + 1, end, postIndex);
    root->left  = buildTree(inorder, postorder, start, pos - 1, postIndex);

    return root;
}

// Preorder traversal
void preorder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int inorder[n], postorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    int postIndex = n - 1;

    Node* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);

    preorder(root);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

// Definition of Tree Node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to search in BST
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    while (root != NULL) {
        if (root->val == val) {
            return root;
        } else if (val < root->val) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return NULL;
}

// Preorder traversal to print result
void preorder(struct TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    // Creating tree: [4,2,7,1,3]
    struct TreeNode* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(7);
    root->left->left = createNode(1);
    root->left->right = createNode(3);

    int val = 2;

    struct TreeNode* result = searchBST(root, val);

    if (result != NULL) {
        printf("Subtree: ");
        preorder(result);   // Output: 2 1 3
    } else {
        printf("Value not found");
    }

    return 0;
}
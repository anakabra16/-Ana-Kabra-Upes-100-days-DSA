#include <stdio.h>
#include <stdlib.h>

// Tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create new node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Check mirror
int isMirror(struct TreeNode* t1, struct TreeNode* t2) {
    if (t1 == NULL && t2 == NULL)
        return 1;
    if (t1 == NULL || t2 == NULL)
        return 0;

    return (t1->val == t2->val) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

// Main symmetric function
int isSymmetric(struct TreeNode* root) {
    return isMirror(root, root);
}
#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int cameras = 0;

// DFS function
int dfs(struct TreeNode* root) {
    if (root == NULL)
        return 2; // NULL nodes are covered

    int left = dfs(root->left);
    int right = dfs(root->right);

    // If any child is not covered → place camera
    if (left == 0 || right == 0) {
        cameras++;
        return 1; // has camera
    }

    // If any child has camera → covered
    if (left == 1 || right == 1) {
        return 2;
    }

    // Otherwise → not covered
    return 0;
}

// Main function
int minCameraCover(struct TreeNode* root) {
    if (dfs(root) == 0)
        cameras++;

    return cameras;
}
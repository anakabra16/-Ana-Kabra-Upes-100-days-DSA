#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int* preorderTraversal(struct TreeNode* root, int* returnSize) {

    int* result = (int*)malloc(sizeof(int)*100);
    struct TreeNode* stack[100];
    int top = -1;
    int index = 0;

    if(root != NULL)
        stack[++top] = root;

    while(top >= 0) {

        struct TreeNode* node = stack[top--];
        result[index++] = node->val;

        if(node->right)
            stack[++top] = node->right;

        if(node->left)
            stack[++top] = node->left;
    }

    *returnSize = index;
    return result;
}
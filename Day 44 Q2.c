#include <stdlib.h>

void dfs(struct TreeNode *root, int *result, int *returnSize) {
  if (root == NULL)
    return;

  result[(*returnSize)++] = root->val;  // Root
  dfs(root->left, result, returnSize);  // Left
  dfs(root->right, result, returnSize); // Right
}

int *preorderTraversal(struct TreeNode *root, int *returnSize) {
  int *result = (int *)malloc(sizeof(int) * 100);
  *returnSize = 0;

  dfs(root, result, returnSize);
  return result;
}
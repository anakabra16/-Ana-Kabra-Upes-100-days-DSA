#include <stdlib.h>

void dfs(struct TreeNode *root, int *result, int *returnSize) {
  if (root == NULL)
    return;

  dfs(root->left, result, returnSize);
  result[(*returnSize)++] = root->val;
  dfs(root->right, result, returnSize);
}

int *inorderTraversal(struct TreeNode *root, int *returnSize) {
  int *result = (int *)malloc(sizeof(int) * 100);
  *returnSize = 0;

  dfs(root, result, returnSize);
  return result;
}
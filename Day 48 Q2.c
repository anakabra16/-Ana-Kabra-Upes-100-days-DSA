int sumOfLeftLeaves(struct TreeNode *root) {
  if (root == NULL)
    return 0;

  int sum = 0;

  // check left child
  if (root->left != NULL) {
    // if left child is leaf
    if (root->left->left == NULL && root->left->right == NULL) {
      sum += root->left->val;
    } else {
      sum += sumOfLeftLeaves(root->left);
    }
  }

  // always check right subtree
  sum += sumOfLeftLeaves(root->right);

  return sum;
}
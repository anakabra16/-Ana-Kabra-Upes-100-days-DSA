#include <stdlib.h>

int **zigzagLevelOrder(struct TreeNode *root, int *returnSize,
                       int **returnColumnSizes) {
  if (!root) {
    *returnSize = 0;
    return NULL;
  }

  struct TreeNode *queue[2000];
  int front = 0, rear = 0;

  queue[rear++] = root;

  int **result = (int **)malloc(2000 * sizeof(int *));
  *returnColumnSizes = (int *)malloc(2000 * sizeof(int));

  int level = 0;

  while (front < rear) {
    int size = rear - front;

    result[level] = (int *)malloc(size * sizeof(int));
    (*returnColumnSizes)[level] = size;

    int leftToRight = (level % 2 == 0);

    for (int i = 0; i < size; i++) {
      struct TreeNode *node = queue[front++];

      int index = leftToRight ? i : (size - 1 - i);
      result[level][index] = node->val;

      if (node->left)
        queue[rear++] = node->left;
      if (node->right)
        queue[rear++] = node->right;
    }

    level++;
  }

  *returnSize = level;
  return result;
}
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

// create node
struct Node *newNode(int val) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->data = val;
  node->left = node->right = NULL;
  return node;
}

// build tree from level order
struct Node *buildTree(int arr[], int n) {
  if (n == 0 || arr[0] == -1)
    return NULL;

  struct Node *root = newNode(arr[0]);

  struct Node *queue[1000];
  int front = 0, rear = 0;

  queue[rear++] = root;
  int i = 1;

  while (i < n) {
    struct Node *curr = queue[front++];

    if (i < n && arr[i] != -1) {
      curr->left = newNode(arr[i]);
      queue[rear++] = curr->left;
    }
    i++;

    if (i < n && arr[i] != -1) {
      curr->right = newNode(arr[i]);
      queue[rear++] = curr->right;
    }
    i++;
  }

  return root;
}

// count leaf nodes
int countLeaves(struct Node *root) {
  if (root == NULL)
    return 0;

  if (root->left == NULL && root->right == NULL)
    return 1;

  return countLeaves(root->left) + countLeaves(root->right);
}

int main() {
  int n;
  scanf("%d", &n);

  int arr[n];
  for (int i = 0; i < n; i++)
    scanf("%d", &arr[i]);

  struct Node *root = buildTree(arr, n);

  printf("%d", countLeaves(root));

  return 0;
}
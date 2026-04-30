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

// insert into BST
struct Node *insert(struct Node *root, int val) {
  if (root == NULL)
    return newNode(val);

  if (val < root->data)
    root->left = insert(root->left, val);
  else
    root->right = insert(root->right, val);

  return root;
}

// find LCA
struct Node *LCA(struct Node *root, int p, int q) {

  while (root != NULL) {

    if (p < root->data && q < root->data)
      root = root->left;

    else if (p > root->data && q > root->data)
      root = root->right;

    else
      return root; // split point
  }

  return NULL;
}

int main() {
  int n;
  scanf("%d", &n);

  struct Node *root = NULL;

  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    root = insert(root, x);
  }

  int p, q;
  scanf("%d %d", &p, &q);

  struct Node *ans = LCA(root, p, q);

  if (ans)
    printf("%d", ans->data);

  return 0;
}
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

    // left child
    if (i < n && arr[i] != -1) {
      curr->left = newNode(arr[i]);
      queue[rear++] = curr->left;
    }
    i++;

    // right child
    if (i < n && arr[i] != -1) {
      curr->right = newNode(arr[i]);
      queue[rear++] = curr->right;
    }
    i++;
  }

  return root;
}

// inorder
void inorder(struct Node *root) {
  if (root == NULL)
    return;
  inorder(root->left);
  printf("%d ", root->data);
  inorder(root->right);
}

// preorder
void preorder(struct Node *root) {
  if (root == NULL)
    return;
  printf("%d ", root->data);
  preorder(root->left);
  preorder(root->right);
}

// postorder
void postorder(struct Node *root) {
  if (root == NULL)
    return;
  postorder(root->left);
  postorder(root->right);
  printf("%d ", root->data);
}

int main() {
  int n;
  scanf("%d", &n);

  int arr[n];
  for (int i = 0; i < n; i++)
    scanf("%d", &arr[i]);

  struct Node *root = buildTree(arr, n);

  inorder(root);
  printf("\n");

  preorder(root);
  printf("\n");

  postorder(root);

  return 0;
}
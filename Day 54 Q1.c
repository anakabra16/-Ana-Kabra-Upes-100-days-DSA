#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

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

// build tree
struct Node *buildTree(int arr[], int n) {
  if (n == 0 || arr[0] == -1)
    return NULL;

  struct Node *root = newNode(arr[0]);

  struct Node *queue[MAX];
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

// zigzag traversal
void zigzag(struct Node *root) {
  if (root == NULL)
    return;

  struct Node *queue[MAX];
  int front = 0, rear = 0;

  queue[rear++] = root;

  int leftToRight = 1;

  while (front < rear) {
    int size = rear - front;
    int level[MAX];

    for (int i = 0; i < size; i++) {
      struct Node *curr = queue[front++];
      level[i] = curr->data;

      if (curr->left)
        queue[rear++] = curr->left;
      if (curr->right)
        queue[rear++] = curr->right;
    }

    // print level
    if (leftToRight) {
      for (int i = 0; i < size; i++)
        printf("%d ", level[i]);
    } else {
      for (int i = size - 1; i >= 0; i--)
        printf("%d ", level[i]);
    }

    leftToRight = !leftToRight;
  }
}

int main() {
  int n;
  scanf("%d", &n);

  int arr[n];
  for (int i = 0; i < n; i++)
    scanf("%d", &arr[i]);

  struct Node *root = buildTree(arr, n);

  zigzag(root);

  return 0;
}
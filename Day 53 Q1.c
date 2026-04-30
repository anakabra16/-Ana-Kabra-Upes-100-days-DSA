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

// vertical order traversal
void verticalOrder(struct Node *root) {
  if (root == NULL)
    return;

  struct Node *queue[MAX];
  int hd[MAX];

  int front = 0, rear = 0;

  // map: HD -> list
  int map[2000][100]; // store values
  int count[2000] = {0};

  int offset = 1000; // to handle negative HD

  int minHD = 1000, maxHD = -1000;

  queue[rear] = root;
  hd[rear++] = 0;

  while (front < rear) {
    struct Node *curr = queue[front];
    int currHD = hd[front++];

    int index = currHD + offset;

    map[index][count[index]++] = curr->data;

    if (currHD < minHD)
      minHD = currHD;
    if (currHD > maxHD)
      maxHD = currHD;

    if (curr->left) {
      queue[rear] = curr->left;
      hd[rear++] = currHD - 1;
    }

    if (curr->right) {
      queue[rear] = curr->right;
      hd[rear++] = currHD + 1;
    }
  }

  // print vertical order
  for (int i = minHD; i <= maxHD; i++) {
    int idx = i + offset;
    for (int j = 0; j < count[idx]; j++) {
      printf("%d ", map[idx][j]);
    }
    printf("\n");
  }
}

int main() {
  int n;
  scanf("%d", &n);

  int arr[n];
  for (int i = 0; i < n; i++)
    scanf("%d", &arr[i]);

  struct Node *root = buildTree(arr, n);

  verticalOrder(root);

  return 0;
}
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

// search in BST
struct Node *search(struct Node *root, int key) {
  if (root == NULL || root->data == key)
    return root;

  if (key < root->data)
    return search(root->left, key);
  else
    return search(root->right, key);
}
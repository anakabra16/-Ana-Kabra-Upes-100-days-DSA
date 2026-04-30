#include <stdlib.h>

// Map (val → cloned node)
struct Node *map[101];

struct Node *clone(struct Node *node) {
  if (!node)
    return NULL;

  // If already cloned
  if (map[node->val])
    return map[node->val];

  // Create new node
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->val = node->val;
  newNode->numNeighbors = node->numNeighbors;
  newNode->neighbors =
      (struct Node **)malloc(node->numNeighbors * sizeof(struct Node *));

  map[node->val] = newNode;

  // Clone neighbors
  for (int i = 0; i < node->numNeighbors; i++) {
    newNode->neighbors[i] = clone(node->neighbors[i]);
  }

  return newNode;
}

struct Node *cloneGraph(struct Node *s) {
  if (!s)
    return NULL;

  // Initialize map
  for (int i = 0; i <= 100; i++) {
    map[i] = NULL;
  }

  return clone(s);
}
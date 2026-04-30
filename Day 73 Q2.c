#include <stdlib.h>

int parent[1001];

// Find with path compression
int find(int x) {
  if (parent[x] != x)
    parent[x] = find(parent[x]);
  return parent[x];
}

// Union
void unionSet(int x, int y) {
  int px = find(x);
  int py = find(y);
  if (px != py) {
    parent[px] = py;
  }
}

int *findRedundantConnection(int **edges, int edgesSize, int *edgesColSize,
                             int *returnSize) {
  // Initialize DSU
  for (int i = 1; i <= edgesSize; i++) {
    parent[i] = i;
  }

  int *result = (int *)malloc(2 * sizeof(int));

  for (int i = 0; i < edgesSize; i++) {
    int u = edges[i][0];
    int v = edges[i][1];

    // If already connected → cycle
    if (find(u) == find(v)) {
      result[0] = u;
      result[1] = v;
      *returnSize = 2;
      return result;
    }

    unionSet(u, v);
  }

  *returnSize = 0;
  return NULL;
}
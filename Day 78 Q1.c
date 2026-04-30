#include <limits.h>
#include <stdio.h>


#define MAX 100

int graph[MAX][MAX];

int minKey(int key[], int mstSet[], int n) {
  int min = INT_MAX, minIndex;

  for (int v = 0; v < n; v++) {
    if (!mstSet[v] && key[v] < min) {
      min = key[v];
      minIndex = v;
    }
  }
  return minIndex;
}

int prim(int n) {
  int parent[MAX];
  int key[MAX];
  int mstSet[MAX] = {0};

  for (int i = 0; i < n; i++) {
    key[i] = INT_MAX;
  }

  key[0] = 0; // start from node 0
  parent[0] = -1;

  for (int count = 0; count < n - 1; count++) {
    int u = minKey(key, mstSet, n);
    mstSet[u] = 1;

    for (int v = 0; v < n; v++) {
      if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
        parent[v] = u;
        key[v] = graph[u][v];
      }
    }
  }

  // total weight
  int total = 0;
  for (int i = 1; i < n; i++) {
    total += key[i];
  }

  return total;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  // initialize graph
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      graph[i][j] = 0;

  for (int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);

    // convert 1-based → 0-based
    u--;
    v--;

    graph[u][v] = w;
    graph[v][u] = w;
  }

  int result = prim(n);
  printf("%d", result);

  return 0;
}
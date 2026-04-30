#include <stdlib.h>

void dfs(int **graph, int n, int city, int *visited) {
  visited[city] = 1;

  for (int i = 0; i < n; i++) {
    if (graph[city][i] == 1 && !visited[i]) {
      dfs(graph, n, i, visited);
    }
  }
}

int findCircleNum(int **isConnected, int isConnectedSize,
                  int *isConnectedColSize) {
  int n = isConnectedSize;
  int visited[200] = {0};
  int provinces = 0;

  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      dfs(isConnected, n, i, visited);
      provinces++;
    }
  }

  return provinces;
}
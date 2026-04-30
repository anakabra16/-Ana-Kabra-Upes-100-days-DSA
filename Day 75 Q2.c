#include <stdbool.h>

bool isBipartite(int **graph, int graphSize, int *graphColSize) {
  int color[100];

  for (int i = 0; i < graphSize; i++) {
    color[i] = -1; // unvisited
  }

  int queue[100];

  for (int start = 0; start < graphSize; start++) {
    if (color[start] != -1)
      continue;

    int front = 0, rear = 0;

    queue[rear++] = start;
    color[start] = 0;

    while (front < rear) {
      int u = queue[front++];

      for (int i = 0; i < graphColSize[u]; i++) {
        int v = graph[u][i];

        if (color[v] == -1) {
          color[v] = 1 - color[u];
          queue[rear++] = v;
        } else if (color[v] == color[u]) {
          return false; // conflict
        }
      }
    }
  }

  return true;
}
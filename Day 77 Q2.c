#include <stdlib.h>

int timeCounter;

void dfs(int u, int parent, int *disc, int *low, int **graph, int *sizes,
         int **result, int *returnSize) {

  disc[u] = low[u] = ++timeCounter;

  for (int i = 0; i < sizes[u]; i++) {
    int v = graph[u][i];

    if (v == parent)
      continue;

    if (disc[v] == 0) {
      dfs(v, u, disc, low, graph, sizes, result, returnSize);

      low[u] = low[u] < low[v] ? low[u] : low[v];

      if (low[v] > disc[u]) {
        result[*returnSize][0] = u;
        result[*returnSize][1] = v;
        (*returnSize)++;
      }
    } else {
      low[u] = low[u] < disc[v] ? low[u] : disc[v];
    }
  }
}

int **criticalConnections(int n, int **connections, int connectionsSize,
                          int *connectionsColSize, int *returnSize,
                          int **returnColumnSizes) {

  int *degree = (int *)calloc(n, sizeof(int));

  // Step 1: Count degrees
  for (int i = 0; i < connectionsSize; i++) {
    degree[connections[i][0]]++;
    degree[connections[i][1]]++;
  }

  // Step 2: Allocate exact memory
  int **graph = (int **)malloc(n * sizeof(int *));
  int *sizes = (int *)calloc(n, sizeof(int));

  for (int i = 0; i < n; i++) {
    graph[i] = (int *)malloc(degree[i] * sizeof(int));
  }

  // Step 3: Fill graph
  for (int i = 0; i < connectionsSize; i++) {
    int u = connections[i][0];
    int v = connections[i][1];

    graph[u][sizes[u]++] = v;
    graph[v][sizes[v]++] = u;
  }

  int *disc = (int *)calloc(n, sizeof(int));
  int *low = (int *)calloc(n, sizeof(int));

  int **result = (int **)malloc(connectionsSize * sizeof(int *));
  *returnColumnSizes = (int *)malloc(connectionsSize * sizeof(int));

  for (int i = 0; i < connectionsSize; i++) {
    result[i] = (int *)malloc(2 * sizeof(int));
    (*returnColumnSizes)[i] = 2;
  }

  *returnSize = 0;
  timeCounter = 0;

  for (int i = 0; i < n; i++) {
    if (disc[i] == 0) {
      dfs(i, -1, disc, low, graph, sizes, result, returnSize);
    }
  }

  return result;
}
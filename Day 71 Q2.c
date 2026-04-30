#include <limits.h>
#include <stdio.h>
#include <stdlib.h>


int minCostConnectPoints(int **points, int pointsSize, int *pointsColSize) {
  int n = pointsSize;

  int minDist[n];
  int visited[n];

  for (int i = 0; i < n; i++) {
    minDist[i] = INT_MAX;
    visited[i] = 0;
  }

  minDist[0] = 0;
  int result = 0;

  for (int i = 0; i < n; i++) {
    int u = -1;

    // Find min distance node
    for (int j = 0; j < n; j++) {
      if (!visited[j] && (u == -1 || minDist[j] < minDist[u])) {
        u = j;
      }
    }

    visited[u] = 1;
    result += minDist[u];

    // Update distances
    for (int v = 0; v < n; v++) {
      if (!visited[v]) {
        int cost =
            abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);

        if (cost < minDist[v]) {
          minDist[v] = cost;
        }
      }
    }
  }

  return result;
}
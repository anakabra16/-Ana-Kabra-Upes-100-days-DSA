#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
  int node;
  int cost;
  int stops;
} State;

int findCheapestPrice(int n, int **flights, int flightsSize,
                      int *flightsColSize, int src, int dst, int k) {
  // Build graph
  int graph[MAX][MAX];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      graph[i][j] = -1;
    }
  }

  for (int i = 0; i < flightsSize; i++) {
    int u = flights[i][0];
    int v = flights[i][1];
    int w = flights[i][2];
    graph[u][v] = w;
  }

  int dist[MAX];
  for (int i = 0; i < n; i++) {
    dist[i] = INT_MAX;
  }

  // Queue
  State queue[10000];
  int front = 0, rear = 0;

  queue[rear++] = (State){src, 0, 0};
  dist[src] = 0;

  while (front < rear) {
    State curr = queue[front++];

    if (curr.stops > k)
      continue;

    for (int v = 0; v < n; v++) {
      if (graph[curr.node][v] != -1) {
        int newCost = curr.cost + graph[curr.node][v];

        if (newCost < dist[v]) {
          dist[v] = newCost;
          queue[rear++] = (State){v, newCost, curr.stops + 1};
        }
      }
    }
  }

  return dist[dst] == INT_MAX ? -1 : dist[dst];
}
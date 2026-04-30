#include <limits.h>
#include <stdio.h>

#define MAX 100

// Edge structure
struct Edge {
  int u, v, w;
};

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  struct Edge edges[MAX];

  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
  }

  int src;
  scanf("%d", &src);

  int dist[MAX];

  // initialize
  for (int i = 0; i < n; i++)
    dist[i] = INT_MAX;

  dist[src] = 0;

  // relax edges (V-1 times)
  for (int i = 1; i <= n - 1; i++) {
    for (int j = 0; j < m; j++) {
      int u = edges[j].u;
      int v = edges[j].v;
      int w = edges[j].w;

      if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
      }
    }
  }

  // check negative cycle
  for (int j = 0; j < m; j++) {
    int u = edges[j].u;
    int v = edges[j].v;
    int w = edges[j].w;

    if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
      printf("NEGATIVE CYCLE");
      return 0;
    }
  }

  // print shortest distances
  for (int i = 0; i < n; i++) {
    printf("%d -> %d\n", i, dist[i]);
  }

  return 0;
}
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// adjacency list node
struct Node {
  int vertex, weight;
  struct Node *next;
};

// graph
struct Graph {
  int V;
  struct Node *adj[MAX];
};

// create node
struct Node *createNode(int v, int w) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->vertex = v;
  node->weight = w;
  node->next = NULL;
  return node;
}

// add edge
void addEdge(struct Graph *graph, int u, int v, int w) {
  struct Node *node = createNode(v, w);
  node->next = graph->adj[u];
  graph->adj[u] = node;
}

// simple min extraction (no heap for simplicity)
int minDistance(int dist[], int visited[], int V) {
  int min = INT_MAX, index = -1;

  for (int i = 0; i < V; i++) {
    if (!visited[i] && dist[i] < min) {
      min = dist[i];
      index = i;
    }
  }
  return index;
}

// Dijkstra
void dijkstra(struct Graph *graph, int src) {
  int dist[MAX];
  int visited[MAX] = {0};

  for (int i = 0; i < graph->V; i++)
    dist[i] = INT_MAX;

  dist[src] = 0;

  for (int i = 0; i < graph->V - 1; i++) {
    int u = minDistance(dist, visited, graph->V);

    if (u == -1)
      break;

    visited[u] = 1;

    struct Node *temp = graph->adj[u];

    while (temp) {
      int v = temp->vertex;
      int w = temp->weight;

      if (!visited[v] && dist[u] != INT_MAX && dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
      }

      temp = temp->next;
    }
  }

  // print result
  for (int i = 0; i < graph->V; i++) {
    printf("%d -> %d\n", i, dist[i]);
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  struct Graph graph;
  graph.V = n;

  for (int i = 0; i < n; i++)
    graph.adj[i] = NULL;

  for (int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    addEdge(&graph, u, v, w);
  }

  int src;
  scanf("%d", &src);

  dijkstra(&graph, src);

  return 0;
}
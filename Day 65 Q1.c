#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure
struct Node {
  int vertex;
  struct Node *next;
};

// Graph
struct Graph {
  int V;
  struct Node *adj[MAX];
};

// create node
struct Node *createNode(int v) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->vertex = v;
  node->next = NULL;
  return node;
}

// add edge (undirected)
void addEdge(struct Graph *graph, int u, int v) {
  struct Node *node = createNode(v);
  node->next = graph->adj[u];
  graph->adj[u] = node;

  node = createNode(u);
  node->next = graph->adj[v];
  graph->adj[v] = node;
}

// DFS cycle detection
int dfs(struct Graph *graph, int v, int visited[], int parent) {
  visited[v] = 1;

  struct Node *temp = graph->adj[v];

  while (temp) {
    int neighbor = temp->vertex;

    if (!visited[neighbor]) {
      if (dfs(graph, neighbor, visited, v))
        return 1;
    } else if (neighbor != parent) {
      return 1; // cycle found
    }

    temp = temp->next;
  }

  return 0;
}

// check cycle
int hasCycle(struct Graph *graph) {
  int visited[MAX] = {0};

  for (int i = 0; i < graph->V; i++) {
    if (!visited[i]) {
      if (dfs(graph, i, visited, -1))
        return 1;
    }
  }

  return 0;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  struct Graph graph;
  graph.V = n;

  for (int i = 0; i < n; i++)
    graph.adj[i] = NULL;

  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    addEdge(&graph, u, v);
  }

  if (hasCycle(&graph))
    printf("YES");
  else
    printf("NO");

  return 0;
}
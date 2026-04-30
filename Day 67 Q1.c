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

// add edge (DIRECTED)
void addEdge(struct Graph *graph, int u, int v) {
  struct Node *node = createNode(v);
  node->next = graph->adj[u];
  graph->adj[u] = node;
}

// DFS topo
void dfsTopo(struct Graph *graph, int v, int visited[], int stack[], int *top) {
  visited[v] = 1;

  struct Node *temp = graph->adj[v];

  while (temp) {
    if (!visited[temp->vertex]) {
      dfsTopo(graph, temp->vertex, visited, stack, top);
    }
    temp = temp->next;
  }

  stack[(*top)++] = v; // push after recursion
}

// topological sort
void topoSort(struct Graph *graph) {
  int visited[MAX] = {0};
  int stack[MAX];
  int top = 0;

  for (int i = 0; i < graph->V; i++) {
    if (!visited[i]) {
      dfsTopo(graph, i, visited, stack, &top);
    }
  }

  // print in reverse order
  for (int i = top - 1; i >= 0; i--) {
    printf("%d ", stack[i]);
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
    int u, v;
    scanf("%d %d", &u, &v);
    addEdge(&graph, u, v);
  }

  topoSort(&graph);

  return 0;
}
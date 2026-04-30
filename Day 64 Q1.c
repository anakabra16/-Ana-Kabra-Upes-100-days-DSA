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

// BFS
void BFS(struct Graph *graph, int start) {
  int visited[MAX] = {0};
  int queue[MAX];

  int front = 0, rear = 0;

  // start node
  queue[rear++] = start;
  visited[start] = 1;

  while (front < rear) {
    int curr = queue[front++];
    printf("%d ", curr);

    struct Node *temp = graph->adj[curr];

    while (temp) {
      if (!visited[temp->vertex]) {
        visited[temp->vertex] = 1;
        queue[rear++] = temp->vertex;
      }
      temp = temp->next;
    }
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

  int start;
  scanf("%d", &start);

  BFS(&graph, start);

  return 0;
}
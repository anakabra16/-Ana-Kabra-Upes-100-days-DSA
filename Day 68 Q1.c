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

// Kahn's Algorithm
void topoSort(struct Graph *graph) {
  int indegree[MAX] = {0};

  // calculate indegree
  for (int i = 0; i < graph->V; i++) {
    struct Node *temp = graph->adj[i];
    while (temp) {
      indegree[temp->vertex]++;
      temp = temp->next;
    }
  }

  // queue
  int queue[MAX];
  int front = 0, rear = 0;

  // push nodes with indegree 0
  for (int i = 0; i < graph->V; i++) {
    if (indegree[i] == 0)
      queue[rear++] = i;
  }

  int count = 0;

  while (front < rear) {
    int curr = queue[front++];
    printf("%d ", curr);
    count++;

    struct Node *temp = graph->adj[curr];

    while (temp) {
      indegree[temp->vertex]--;

      if (indegree[temp->vertex] == 0)
        queue[rear++] = temp->vertex;

      temp = temp->next;
    }
  }

  // cycle check
  if (count != graph->V) {
    printf("\nCycle detected → Topological sort not possible");
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
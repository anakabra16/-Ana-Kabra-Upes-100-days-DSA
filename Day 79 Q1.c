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

// min heap node
struct HeapNode {
  int v, dist;
};

// min heap
struct MinHeap {
  int size;
  struct HeapNode arr[MAX];
};

// create node
struct Node *createNode(int v, int w) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->vertex = v;
  node->weight = w;
  node->next = NULL;
  return node;
}

// add edge (undirected)
void addEdge(struct Graph *graph, int u, int v, int w) {
  struct Node *node = createNode(v, w);
  node->next = graph->adj[u];
  graph->adj[u] = node;

  node = createNode(u, w);
  node->next = graph->adj[v];
  graph->adj[v] = node;
}

// swap
void swap(struct HeapNode *a, struct HeapNode *b) {
  struct HeapNode t = *a;
  *a = *b;
  *b = t;
}

// heapify
void heapifyUp(struct MinHeap *heap, int i) {
  while (i > 0) {
    int p = (i - 1) / 2;
    if (heap->arr[p].dist > heap->arr[i].dist) {
      swap(&heap->arr[p], &heap->arr[i]);
      i = p;
    } else
      break;
  }
}

// push
void push(struct MinHeap *heap, int v, int dist) {
  heap->arr[heap->size].v = v;
  heap->arr[heap->size].dist = dist;
  heapifyUp(heap, heap->size);
  heap->size++;
}

// heapify down
void heapifyDown(struct MinHeap *heap, int i) {
  while (1) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int smallest = i;

    if (l < heap->size && heap->arr[l].dist < heap->arr[smallest].dist)
      smallest = l;
    if (r < heap->size && heap->arr[r].dist < heap->arr[smallest].dist)
      smallest = r;

    if (smallest != i) {
      swap(&heap->arr[i], &heap->arr[smallest]);
      i = smallest;
    } else
      break;
  }
}

// pop min
struct HeapNode pop(struct MinHeap *heap) {
  struct HeapNode root = heap->arr[0];
  heap->arr[0] = heap->arr[--heap->size];
  heapifyDown(heap, 0);
  return root;
}

// Dijkstra
void dijkstra(struct Graph *graph, int src) {
  int dist[MAX];

  for (int i = 0; i < graph->V; i++)
    dist[i] = INT_MAX;

  dist[src] = 0;

  struct MinHeap heap;
  heap.size = 0;

  push(&heap, src, 0);

  while (heap.size > 0) {
    struct HeapNode curr = pop(&heap);
    int u = curr.v;

    struct Node *temp = graph->adj[u];

    while (temp) {
      int v = temp->vertex;
      int w = temp->weight;

      if (dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        push(&heap, v, dist[v]);
      }

      temp = temp->next;
    }
  }

  // print result
  for (int i = 0; i < graph->V; i++) {
    printf("%d ", dist[i]);
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

    u--;
    v--; // convert to 0-based

    addEdge(&graph, u, v, w);
  }

  int src;
  scanf("%d", &src);
  src--; // 0-based

  dijkstra(&graph, src);

  return 0;
}
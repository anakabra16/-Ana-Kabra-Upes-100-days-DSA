#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 1000

// Adjacency list node
struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

// Graph structure
struct Node* adj[MAX_VERTICES];

void addEdge(int u, int v, int w) {
    // Add edge u -> v
    struct Node* newNode1 = (struct Node*)malloc(sizeof(struct Node));
    newNode1->vertex = v;
    newNode1->weight = w;
    newNode1->next = adj[u];
    adj[u] = newNode1;

    // Add edge v -> u
    struct Node* newNode2 = (struct Node*)malloc(sizeof(struct Node));
    newNode2->vertex = u;
    newNode2->weight = w;
    newNode2->next = adj[v];
    adj[v] = newNode2;
}

// Min Heap Node representing priority queue elements (distance, vertex)
struct MinHeapNode {
    int vertex;
    int distance;
};

// Min Heap structure
struct MinHeap {
    int size;
    int capacity;
    int *pos;
    struct MinHeapNode **array;
};

struct MinHeapNode* newMinHeapNode(int v, int d) {
    struct MinHeapNode* minHeapNode = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    minHeapNode->vertex = v;
    minHeapNode->distance = d;
    return minHeapNode;
}

struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->pos = (int *)malloc(capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**)malloc(capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest, left, right;
    smallest = idx;
    left = 2 * idx + 1;
    right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->distance < minHeap->array[smallest]->distance)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->distance < minHeap->array[smallest]->distance)
        smallest = right;

    if (smallest != idx) {
        struct MinHeapNode* smallestNode = minHeap->array[smallest];
        struct MinHeapNode* idxNode = minHeap->array[idx];

        // Swap positions in pos mapping
        minHeap->pos[smallestNode->vertex] = idx;
        minHeap->pos[idxNode->vertex] = smallest;

        // Swap nodes
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);

        minHeapify(minHeap, smallest);
    }
}

int isEmpty(struct MinHeap* minHeap) {
    return minHeap->size == 0;
}

struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
    if (isEmpty(minHeap))
        return NULL;

    struct MinHeapNode* root = minHeap->array[0];
    struct MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;

    minHeap->pos[root->vertex] = minHeap->size - 1;
    minHeap->pos[lastNode->vertex] = 0;

    --minHeap->size;
    minHeapify(minHeap, 0);

    return root;
}

void decreaseKey(struct MinHeap* minHeap, int v, int dist) {
    int i = minHeap->pos[v];
    minHeap->array[i]->distance = dist;

    while (i && minHeap->array[i]->distance < minHeap->array[(i - 1) / 2]->distance) {
        minHeap->pos[minHeap->array[i]->vertex] = (i - 1) / 2;
        minHeap->pos[minHeap->array[(i - 1) / 2]->vertex] = i;
        swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int isInMinHeap(struct MinHeap *minHeap, int v) {
    if (minHeap->pos[v] < minHeap->size)
        return 1;
    return 0;
}

void dijkstra(int V, int src) {
    int dist[MAX_VERTICES];
    struct MinHeap* minHeap = createMinHeap(V);

    for (int v = 0; v < V; ++v) {
        dist[v] = INT_MAX;
        minHeap->array[v] = newMinHeapNode(v, dist[v]);
        minHeap->pos[v] = v;
    }

    minHeap->size = V;
    dist[src] = 0;
    decreaseKey(minHeap, src, dist[src]);

    while (!isEmpty(minHeap)) {
        struct MinHeapNode* minHeapNode = extractMin(minHeap);
        int u = minHeapNode->vertex;

        struct Node* pCrawl = adj[u];
        while (pCrawl != NULL) {
            int v = pCrawl->vertex;
            if (isInMinHeap(minHeap, v) && dist[u] != INT_MAX && pCrawl->weight + dist[u] < dist[v]) {
                dist[v] = dist[u] + pCrawl->weight;
                decreaseKey(minHeap, v, dist[v]);
            }
            pCrawl = pCrawl->next;
        }
        free(minHeapNode);
    }

    // Print shortest distances
    for (int i = 0; i < V; ++i) {
        if (dist[i] == INT_MAX)
            printf("INF ");
        else
            printf("%d ", dist[i]);
    }
    printf("\n");

    free(minHeap->array);
    free(minHeap->pos);
    free(minHeap);
}

int main() {
    int V, E, S;
    // Read number of vertices V, edges E, and source vertex S
    if (scanf("%d %d %d", &V, &E, &S) != 3) return 0;

    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
    }

    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    dijkstra(V, S);

    return 0;
}

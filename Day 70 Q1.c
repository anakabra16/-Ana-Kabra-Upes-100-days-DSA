#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Edge structure
struct Edge {
    int u, v, weight;
};

// Graph structure
struct Graph {
    int V, E;
    struct Edge* edge;
};

// Function to create a graph with V vertices and E edges
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*) malloc(graph->E * sizeof(struct Edge));
    return graph;
}

// Function to run Bellman-Ford algorithm
void BellmanFord(struct Graph* graph, int src) {
    int V = graph->V;
    int E = graph->E;
    int dist[V];

    // Initialize distances from src to all other vertices as INFINITY
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    // Relax all edges |V| - 1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph->edge[j].u;
            int v = graph->edge[j].v;
            int weight = graph->edge[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative-weight cycles
    // If we get a shorter path, then there is a cycle
    for (int i = 0; i < E; i++) {
        int u = graph->edge[i].u;
        int v = graph->edge[i].v;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("NEGATIVE CYCLE\n");
            return;
        }
    }

    // Print shortest distances
    for (int i = 0; i < V; ++i) {
        if (dist[i] == INT_MAX)
            printf("INF ");
        else
            printf("%d ", dist[i]);
    }
    printf("\n");
}

int main() {
    int n, m, src;
    // Read number of vertices, edges, and source vertex
    if (scanf("%d %d %d", &n, &m, &src) != 3) return 0;

    struct Graph* graph = createGraph(n, m);

    // Read all edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &graph->edge[i].u, &graph->edge[i].v, &graph->edge[i].weight);
    }

    BellmanFord(graph, src);

    free(graph->edge);
    free(graph);

    return 0;
}

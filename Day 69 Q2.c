#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k) {
    Node** adj = (Node**)calloc(n + 1, sizeof(Node*));
    
    for (int i = 0; i < timesSize; i++) {
        int u = times[i][0];
        int v = times[i][1];
        int w = times[i][2];
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->vertex = v;
        newNode->weight = w;
        newNode->next = adj[u];
        adj[u] = newNode;
    }
    
    int* dist = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++) dist[i] = INT_MAX;
    dist[k] = 0;
    
    int* visited = (int*)calloc(n + 1, sizeof(int));
    
    // Simple Dijkstra without heap (O(V^2)) since n <= 100
    for (int i = 1; i <= n; i++) {
        int u = -1;
        int minDist = INT_MAX;
        
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }
        
        if (u == -1) break;
        visited[u] = 1;
        
        Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->vertex;
            int w = temp->weight;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
            temp = temp->next;
        }
    }
    
    int maxDist = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) return -1;
        if (dist[i] > maxDist) maxDist = dist[i];
    }
    
    free(dist);
    free(visited);
    free(adj);
    return maxDist;
}

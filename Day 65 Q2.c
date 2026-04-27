#include <stdio.h>
#include <stdlib.h>

#define MAX 100001

// Adjacency list using linked list
struct Node {
    int data;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];

// Add edge to adjacency list
void addEdge(int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = u;
    newNode->next = adj[v];
    adj[v] = newNode;
}

// DFS with parent tracking to detect cycle
int dfs(int node, int parent) {
    visited[node] = 1;

    struct Node* temp = adj[node];
    while (temp != NULL) {
        int neighbor = temp->data;

        if (!visited[neighbor]) {
            if (dfs(neighbor, node))
                return 1;
        } else if (neighbor != parent) {
            return 1;
        }

        temp = temp->next;
    }
    return 0;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    // Initialize adjacency list
    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    // Read edges
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    // Check all components for cycle
    int hasCycle = 0;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                hasCycle = 1;
                break;
            }
        }
    }

    if (hasCycle)
        printf("true");
    else
        printf("false");

    return 0;
}

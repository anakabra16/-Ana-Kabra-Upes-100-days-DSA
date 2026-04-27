#include <stdio.h>

#define MAX 1000

// Adjacency list
int adj[MAX][MAX];
int adjSize[MAX];
int visited[MAX];

// DFS to detect cycle using parent tracking
int dfs(int node, int parent, int n) {
    visited[node] = 1;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor, node, n))
                return 1;
        } else if (neighbor != parent) {
            // Visited neighbor that is not parent = cycle
            return 1;
        }
    }
    return 0;
}

int main() {
    int n, e;
    scanf("%d %d", &n, &e);

    // Initialize
    for (int i = 0; i < n; i++)
        adjSize[i] = 0;

    // Read edges
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }

    // Initialize visited
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    // Check all components
    int hasCycle = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, n)) {
                hasCycle = 1;
                break;
            }
        }
    }

    if (hasCycle)
        printf("YES");
    else
        printf("NO");

    return 0;
}

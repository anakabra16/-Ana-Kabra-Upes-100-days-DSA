#include <stdio.h>

#define MAX 1000

// Adjacency list
int adj[MAX][MAX];
int adjSize[MAX];
int visited[MAX];
int recStack[MAX];

// DFS with recursion stack to detect cycle in directed graph
int dfs(int node) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor))
                return 1;
        } else if (recStack[neighbor]) {
            // Node is in current recursion stack = cycle
            return 1;
        }
    }

    recStack[node] = 0;
    return 0;
}

int main() {
    int n, e;
    scanf("%d %d", &n, &e);

    // Initialize
    for (int i = 0; i < n; i++) {
        adjSize[i] = 0;
        visited[i] = 0;
        recStack[i] = 0;
    }

    // Read directed edges (u -> v)
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][adjSize[u]++] = v;
    }

    // Check all nodes (for disconnected components)
    int hasCycle = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i)) {
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

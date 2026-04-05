#include <stdio.h>

#define MAX 100

int visited[MAX];

// DFS function
void dfs(int n, int adj[MAX][MAX], int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < n; i++) {
        if (adj[vertex][i] == 1 && !visited[i]) {
            dfs(n, adj, i);
        }
    }
}

int main() {
    int n;

    // Number of vertices
    scanf("%d", &n);

    int adj[MAX][MAX];

    // Input adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    int s;
    // Starting vertex
    scanf("%d", &s);

    // Initialize visited array
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    // Perform DFS
    dfs(n, adj, s);

    return 0;
}
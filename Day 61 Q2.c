#include <stdio.h>

#define MAX 200

int visited[MAX];

// DFS function
void dfs(int isConnected[MAX][MAX], int n, int city) {
    visited[city] = 1;

    for (int i = 0; i < n; i++) {
        if (isConnected[city][i] == 1 && !visited[i]) {
            dfs(isConnected, n, i);
        }
    }
}

int main() {
    int n;

    // Input number of cities
    scanf("%d", &n);

    int isConnected[MAX][MAX];

    // Input adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &isConnected[i][j]);
        }
    }

    // Initialize visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    int provinces = 0;

    // Count provinces
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(isConnected, n, i);
            provinces++;
        }
    }

    // Output result
    printf("%d", provinces);

    return 0;
}
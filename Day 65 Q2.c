#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 
  GeeksforGeeks already defines struct Node and addEdge behind the scenes:
  struct Node {
      int data;
      struct Node* next;
  };
*/

bool dfs(int node, int parent, int* visited, struct Node* adj[]) {
    visited[node] = 1;

    struct Node* temp = adj[node];
    while (temp != NULL) {
        int neighbor = temp->data;

        if (!visited[neighbor]) {
            if (dfs(neighbor, node, visited, adj))
                return true;
        } else if (neighbor != parent) {
            // If an adjacent node is visited and not the parent, there's a cycle
            return true;
        }

        temp = temp->next;
    }
    return false;
}

// Function to detect cycle in an undirected graph
bool isCycle(int V, struct Node* adj[]) {
    int* visited = (int*)calloc(V, sizeof(int));
    
    // Check all components
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, visited, adj)) {
                free(visited);
                return true;
            }
        }
    }
    
    free(visited);
    return false;
}

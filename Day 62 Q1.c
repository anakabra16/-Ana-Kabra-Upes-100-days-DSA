#include <stdio.h>
#include <stdlib.h>

// Node for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge (undirected)
void addEdge(struct Node* adj[], int u, int v) {
    // Add v to u's list
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    // Add u to v's list
    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

// Print adjacency list
void printGraph(struct Node* adj[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        struct Node* temp = adj[i];
        while (temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int n, m;

    // Input vertices and edges
    scanf("%d", &n);
    scanf("%d", &m);

    struct Node* adj[n];

    // Initialize lists
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    int u, v;

    // Input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v); // undirected
    }

    // Print adjacency list
    printGraph(adj, n);

    return 0;
}
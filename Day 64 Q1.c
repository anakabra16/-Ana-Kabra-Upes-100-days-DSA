#include <stdio.h>
#include <stdlib.h>

#define MAX 100

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
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

// Queue implementation
int queue[MAX], front = 0, rear = 0;

void enqueue(int x) {
    queue[rear++] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

// BFS function
void bfs(struct Node* adj[], int n, int start) {
    int visited[MAX] = {0};

    enqueue(start);
    visited[start] = 1;

    while (!isEmpty()) {
        int current = dequeue();
        printf("%d ", current);

        struct Node* temp = adj[current];
        while (temp != NULL) {
            int v = temp->vertex;
            if (!visited[v]) {
                enqueue(v);
                visited[v] = 1;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n, m;

    // Input vertices and edges
    scanf("%d", &n);
    scanf("%d", &m);

    struct Node* adj[MAX];

    // Initialize adjacency list
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    int u, v;

    // Input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    int s;
    // Source vertex
    scanf("%d", &s);

    // Perform BFS
    bfs(adj, n, s);

    return 0;
}
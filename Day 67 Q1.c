#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 1000

struct Node {
    int data;
    struct Node* next;
};

struct Node* adj[MAX_VERTICES];
int visited[MAX_VERTICES];
int stack[MAX_VERTICES];
int top = -1;

void push(int val) {
    stack[++top] = val;
}

int pop() {
    return stack[top--];
}

void addEdge(int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

void dfs(int node) {
    visited[node] = 1;

    struct Node* temp = adj[node];
    while (temp != NULL) {
        int neighbor = temp->data;
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
        temp = temp->next;
    }

    // Push vertex to stack only after all its adjacent vertices are visited
    push(node);
}

int main() {
    int V, E;
    if (scanf("%d %d", &V, &E) != 2) return 0;

    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    // Print the topological sort
    while (top != -1) {
        printf("%d ", pop());
    }
    printf("\n");

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 1000

struct Node {
    int data;
    struct Node* next;
};

struct Node* adj[MAX_VERTICES];
int inDegree[MAX_VERTICES];

void addEdge(int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = adj[u];
    adj[u] = newNode;
    inDegree[v]++;
}

int main() {
    int V, E;
    if (scanf("%d %d", &V, &E) != 2) return 0;

    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
        inDegree[i] = 0;
    }

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    // Enqueue all vertices with in-degree 0
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;
    // Process queue
    while (front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);
        count++;

        // Decrease in-degree of all adjacent vertices
        struct Node* temp = adj[curr];
        while (temp != NULL) {
            int neighbor = temp->data;
            inDegree[neighbor]--;
            // If in-degree becomes 0, enqueue it
            if (inDegree[neighbor] == 0) {
                queue[rear++] = neighbor;
            }
            temp = temp->next;
        }
    }
    printf("\n");

    // Check if there was a cycle
    if (count != V) {
        printf("Cycle detected! Topological sort is not possible for graphs with cycles.\n");
    }

    return 0;
}

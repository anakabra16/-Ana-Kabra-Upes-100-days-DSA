#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    Node** adj = (Node**)calloc(numCourses, sizeof(Node*));
    int* inDegree = (int*)calloc(numCourses, sizeof(int));
    
    for (int i = 0; i < prerequisitesSize; i++) {
        int ai = prerequisites[i][0];
        int bi = prerequisites[i][1];
        // bi must be taken before ai -> directed edge from bi to ai
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = ai;
        newNode->next = adj[bi];
        adj[bi] = newNode;
        inDegree[ai]++;
    }
    
    int* queue = (int*)malloc(numCourses * sizeof(int));
    int front = 0, rear = 0;
    
    for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] == 0) {
            queue[rear++] = i;
        }
    }
    
    int count = 0;
    while (front < rear) {
        int curr = queue[front++];
        count++;
        
        Node* temp = adj[curr];
        while (temp != NULL) {
            int neighbor = temp->data;
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                queue[rear++] = neighbor;
            }
            temp = temp->next;
        }
    }
    
    free(adj);
    free(inDegree);
    free(queue);
    
    return count == numCourses;
}

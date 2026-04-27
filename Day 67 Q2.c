#include <stdio.h>
#include <stdlib.h>

#define MAX_COURSES 2005

struct Node {
    int data;
    struct Node* next;
};

struct Node* adj[MAX_COURSES];
int inDegree[MAX_COURSES];

void addEdge(int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = adj[u];
    adj[u] = newNode;
    inDegree[v]++;
}

int main() {
    int numCourses, prerequisitesLength;
    if (scanf("%d %d", &numCourses, &prerequisitesLength) != 2) return 0;

    for (int i = 0; i < numCourses; i++) {
        adj[i] = NULL;
        inDegree[i] = 0;
    }

    for (int i = 0; i < prerequisitesLength; i++) {
        int ai, bi;
        scanf("%d %d", &ai, &bi);
        // bi must be taken before ai -> directed edge from bi to ai
        addEdge(bi, ai);
    }

    int queue[MAX_COURSES];
    int front = 0, rear = 0;
    int order[MAX_COURSES];
    int count = 0;

    for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    while (front < rear) {
        int curr = queue[front++];
        order[count++] = curr;

        struct Node* temp = adj[curr];
        while (temp != NULL) {
            int neighbor = temp->data;
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                queue[rear++] = neighbor;
            }
            temp = temp->next;
        }
    }

    // If we could topologically sort all courses, print the order
    if (count == numCourses) {
        printf("[");
        for (int i = 0; i < numCourses; i++) {
            printf("%d%s", order[i], (i == numCourses - 1) ? "" : ",");
        }
        printf("]\n");
    } else {
        // Else, it's impossible (cycle exists), return empty array
        printf("[]\n");
    }

    return 0;
}

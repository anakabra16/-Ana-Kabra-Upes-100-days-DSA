#include <stdbool.h>
#include <stdlib.h>

bool canFinish(int numCourses, int **prerequisites, int prerequisitesSize,
               int *prerequisitesColSize) {
  // Step 1: Graph
  int **graph = (int **)malloc(numCourses * sizeof(int *));
  int *indegree = (int *)calloc(numCourses, sizeof(int));
  int *sizes = (int *)calloc(numCourses, sizeof(int));

  for (int i = 0; i < numCourses; i++) {
    graph[i] = (int *)malloc(numCourses * sizeof(int));
  }

  // Step 2: Build graph
  for (int i = 0; i < prerequisitesSize; i++) {
    int a = prerequisites[i][0];
    int b = prerequisites[i][1];

    graph[b][sizes[b]++] = a;
    indegree[a]++;
  }

  // Step 3: Queue
  int queue[numCourses];
  int front = 0, rear = 0;

  for (int i = 0; i < numCourses; i++) {
    if (indegree[i] == 0) {
      queue[rear++] = i;
    }
  }

  int count = 0;

  // Step 4: BFS
  while (front < rear) {
    int node = queue[front++];
    count++;

    for (int i = 0; i < sizes[node]; i++) {
      int neighbor = graph[node][i];
      indegree[neighbor]--;

      if (indegree[neighbor] == 0) {
        queue[rear++] = neighbor;
      }
    }
  }

  // Step 5: Check
  return count == numCourses;
}
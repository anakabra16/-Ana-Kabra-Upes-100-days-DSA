#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10005

// Structure for queue elements
typedef struct {
    int x, y;
} Pair;

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    if (gridSize == 0) return 0;
    int m = gridSize;
    int n = gridColSize[0];
    
    Pair queue[MAX_QUEUE_SIZE];
    int front = 0, rear = 0;
    
    int fresh = 0;
    
    // Initialize queue with all rotten oranges
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                queue[rear].x = i;
                queue[rear].y = j;
                rear++;
            }
            if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }
    
    int minutes = 0;
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    
    // BFS traversal
    while (front != rear && fresh > 0) {
        int size = rear - front;
        
        for (int i = 0; i < size; i++) {
            Pair p = queue[front++];
            
            for (int d = 0; d < 4; d++) {
                int nx = p.x + dirs[d][0];
                int ny = p.y + dirs[d][1];
                
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2; // rot it
                    queue[rear].x = nx;
                    queue[rear].y = ny;
                    rear++;
                    fresh--;
                }
            }
        }
        minutes++;
    }
    
    if (fresh == 0)
        return minutes;
    else
        return -1;
}
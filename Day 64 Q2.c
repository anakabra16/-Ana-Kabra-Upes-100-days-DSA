#include <stdio.h>

#define MAX 10

// Structure for queue elements
typedef struct {
    int x, y;
} Pair;

Pair queue[MAX * MAX];
int front = 0, rear = 0;

// Queue functions
void enqueue(int x, int y) {
    queue[rear].x = x;
    queue[rear].y = y;
    rear++;
}

Pair dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int grid[MAX][MAX];

    // Input grid
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    int fresh = 0;

    // Initialize queue with all rotten oranges
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                enqueue(i, j);
            }
            if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    int minutes = 0;
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    // BFS traversal
    while (!isEmpty() && fresh > 0) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            Pair p = dequeue();

            for (int d = 0; d < 4; d++) {
                int nx = p.x + dirs[d][0];
                int ny = p.y + dirs[d][1];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2; // rot it
                    enqueue(nx, ny);
                    fresh--;
                }
            }
        }

        minutes++;
    }

    // Output result
    if (fresh == 0)
        printf("%d\n", minutes);
    else
        printf("-1\n");

    return 0;
}
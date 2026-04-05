#include <stdio.h>

#define MAX 1000

int visited[MAX];

// DFS function
void dfs(int rooms[MAX][MAX], int roomsColSize[], int room) {
    visited[room] = 1;

    for (int i = 0; i < roomsColSize[room]; i++) {
        int next = rooms[room][i];
        if (!visited[next]) {
            dfs(rooms, roomsColSize, next);
        }
    }
}

int main() {
    int n;

    // Number of rooms
    scanf("%d", &n);

    int rooms[MAX][MAX];
    int roomsColSize[MAX];

    // Input rooms
    // For each room: first input number of keys, then keys
    for (int i = 0; i < n; i++) {
        scanf("%d", &roomsColSize[i]);
        for (int j = 0; j < roomsColSize[i]; j++) {
            scanf("%d", &rooms[i][j]);
        }
    }

    // Initialize visited
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    // Start DFS from room 0
    dfs(rooms, roomsColSize, 0);

    // Check if all rooms are visited
    int canVisitAll = 1;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            canVisitAll = 0;
            break;
        }
    }

    if (canVisitAll)
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
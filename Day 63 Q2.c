#include <stdio.h>

#define MAX 100

int image[MAX][MAX];
int m, n;

// DFS function
void dfs(int r, int c, int oldColor, int newColor) {
    // Boundary check
    if (r < 0 || r >= m || c < 0 || c >= n)
        return;

    // Stop if not matching original color
    if (image[r][c] != oldColor)
        return;

    // Change color
    image[r][c] = newColor;

    // Visit neighbors (4 directions)
    dfs(r + 1, c, oldColor, newColor);
    dfs(r - 1, c, oldColor, newColor);
    dfs(r, c + 1, oldColor, newColor);
    dfs(r, c - 1, oldColor, newColor);
}

int main() {
    int sr, sc, color;

    // Input rows and columns
    scanf("%d %d", &m, &n);

    // Input image matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &image[i][j]);
        }
    }

    // Input starting row, column and new color
    scanf("%d %d %d", &sr, &sc, &color);

    int oldColor = image[sr][sc];

    // If color is same, no need to process
    if (oldColor != color) {
        dfs(sr, sc, oldColor, color);
    }

    // Print updated image
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}
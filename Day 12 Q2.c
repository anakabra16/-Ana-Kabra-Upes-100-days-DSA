#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int a[100][100];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int toeplitz = 1;

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (a[i][j] != a[i-1][j-1]) {
                toeplitz = 0;
                break;
            }
        }
        if (toeplitz == 0)
            break;
    }

    if (toeplitz)
        printf("Toeplitz Matrix");
    else
        printf("Not a Toeplitz Matrix");

    return 0;
}

#include <stdio.h>

void setZeroes(int m, int n, int a[m][n]) {
    int i, j, k;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (a[i][j] == 0) {

                for (k = 0; k < n; k++)
                    if (a[i][k] != 0)
                        a[i][k] = -1;

                for (k = 0; k < m; k++)
                    if (a[k][j] != 0)
                        a[k][j] = -1;
            }
        }
    }

    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            if (a[i][j] == -1)
                a[i][j] = 0;
}

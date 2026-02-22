#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), cmp);

    int l = 0, r = n - 1;
    int minSum = 2147483647;
    int x = arr[l], y = arr[r];

    while (l < r) {
        int sum = arr[l] + arr[r];

        if (abs(sum) < abs(minSum)) {
            minSum = sum;
            x = arr[l];
            y = arr[r];
        }

        if (sum < 0)
            l++;
        else
            r--;
    }

    printf("%d %d", x, y);
    return 0;
}

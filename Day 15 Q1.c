#include <stdio.h>

int main() {
  int m, n;
  scanf("%d %d", &m, &n);

  int arr[m][n];

  // input matrix
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &arr[i][j]);
    }
  }

  int sum = 0;

  // sum of primary diagonal
  for (int i = 0; i < m && i < n; i++) {
    sum += arr[i][i];
  }

  printf("%d\n", sum);

  return 0;
}
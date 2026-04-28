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

  // check square matrix
  if (m != n) {
    printf("Not a Symmetric Matrix\n");
    return 0;
  }

  int isSymmetric = 1;

  // check symmetry
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[i][j] != arr[j][i]) {
        isSymmetric = 0;
        break;
      }
    }
    if (!isSymmetric)
      break;
  }

  if (isSymmetric)
    printf("Symmetric Matrix\n");
  else
    printf("Not a Symmetric Matrix\n");

  return 0;
}
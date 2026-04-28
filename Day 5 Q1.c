#include <stdio.h>

int main() {
  int p, q;

  // input first array
  scanf("%d", &p);
  int a[p];
  for (int i = 0; i < p; i++) {
    scanf("%d", &a[i]);
  }

  // input second array
  scanf("%d", &q);
  int b[q];
  for (int i = 0; i < q; i++) {
    scanf("%d", &b[i]);
  }

  int i = 0, j = 0;

  // merge both arrays
  while (i < p && j < q) {
    if (a[i] <= b[j]) {
      printf("%d ", a[i]);
      i++;
    } else {
      printf("%d ", b[j]);
      j++;
    }
  }

  // remaining elements of a[]
  while (i < p) {
    printf("%d ", a[i]);
    i++;
  }

  // remaining elements of b[]
  while (j < q) {
    printf("%d ", b[j]);
    j++;
  }

  return 0;
}
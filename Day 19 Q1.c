#include <stdio.h>
#include <stdlib.h>

// comparator for qsort
int compare(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int main() {
  int n;
  scanf("%d", &n);

  int arr[n];

  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  // step 1: sort
  qsort(arr, n, sizeof(int), compare);

  int left = 0, right = n - 1;

  int minSum = 1000000000; // large value
  int a, b;

  // step 2: two pointers
  while (left < right) {
    int sum = arr[left] + arr[right];

    // check closest to zero
    if (abs(sum) < abs(minSum)) {
      minSum = sum;
      a = arr[left];
      b = arr[right];
    }

    if (sum < 0)
      left++;
    else
      right--;
  }

  printf("%d %d\n", a, b);

  return 0;
}
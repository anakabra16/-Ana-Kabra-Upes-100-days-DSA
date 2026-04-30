#include <stdlib.h>

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int canPlace(int *pos, int n, int m, int dist) {
  int count = 1;
  int last = pos[0];

  for (int i = 1; i < n; i++) {
    if (pos[i] - last >= dist) {
      count++;
      last = pos[i];
    }
    if (count >= m)
      return 1;
  }

  return 0;
}

int maxDistance(int *position, int n, int m) {
  qsort(position, n, sizeof(int), cmp);

  int left = 1;
  int right = position[n - 1] - position[0];
  int ans = 0;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (canPlace(position, n, m, mid)) {
      ans = mid;      // valid distance
      left = mid + 1; // try bigger
    } else {
      right = mid - 1;
    }
  }

  return ans;
}
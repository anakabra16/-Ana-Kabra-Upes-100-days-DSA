#include <stdio.h>

// Check if allocation is possible
int canAllocate(int arr[], int n, int m, int maxPages) {
  int students = 1;
  int pagesSum = 0;

  for (int i = 0; i < n; i++) {
    if (pagesSum + arr[i] <= maxPages) {
      pagesSum += arr[i];
    } else {
      students++;
      pagesSum = arr[i];

      if (students > m)
        return 0;
    }
  }

  return 1;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  // Edge case
  if (m > n) {
    printf("-1");
    return 0;
  }

  int low = arr[0], high = 0;

  // Find max and sum
  for (int i = 0; i < n; i++) {
    if (arr[i] > low)
      low = arr[i];
    high += arr[i];
  }

  int ans = high;

  // Binary Search
  while (low <= high) {
    int mid = (low + high) / 2;

    if (canAllocate(arr, n, m, mid)) {
      ans = mid; // valid → try smaller
      high = mid - 1;
    } else {
      low = mid + 1; // not valid → increase
    }
  }

  printf("%d", ans);

  return 0;
}
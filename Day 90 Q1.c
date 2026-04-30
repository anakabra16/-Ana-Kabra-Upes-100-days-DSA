#include <stdio.h>

// Check if possible within given maxTime
int canPaint(int arr[], int n, int k, int maxTime) {
  int painters = 1;
  int currentTime = 0;

  for (int i = 0; i < n; i++) {
    if (currentTime + arr[i] <= maxTime) {
      currentTime += arr[i];
    } else {
      painters++;
      currentTime = arr[i];

      if (painters > k)
        return 0;
    }
  }

  return 1;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);

  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
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

    if (canPaint(arr, n, k, mid)) {
      ans = mid; // valid → try smaller
      high = mid - 1;
    } else {
      low = mid + 1; // not valid → increase
    }
  }

  printf("%d", ans);

  return 0;
}
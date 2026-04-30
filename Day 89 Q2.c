#include <stdlib.h>

int canShip(int *weights, int n, int days, int capacity) {
  int daysUsed = 1;
  int currentLoad = 0;

  for (int i = 0; i < n; i++) {
    if (currentLoad + weights[i] > capacity) {
      daysUsed++;
      currentLoad = weights[i];
    } else {
      currentLoad += weights[i];
    }
  }

  return daysUsed <= days;
}

int shipWithinDays(int *weights, int weightsSize, int days) {
  int left = 0, right = 0;

  // determine bounds
  for (int i = 0; i < weightsSize; i++) {
    if (weights[i] > left)
      left = weights[i]; // max weight
    right += weights[i]; // sum
  }

  int ans = right;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (canShip(weights, weightsSize, days, mid)) {
      ans = mid;       // valid capacity
      right = mid - 1; // try smaller
    } else {
      left = mid + 1; // need bigger capacity
    }
  }

  return ans;
}
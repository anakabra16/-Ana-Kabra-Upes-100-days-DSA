#include <limits.h>

long long canEat(int *piles, int n, int k) {
  long long hours = 0;

  for (int i = 0; i < n; i++) {
    // ceil(piles[i] / k)
    hours += (piles[i] + k - 1) / k;
  }

  return hours;
}

int minEatingSpeed(int *piles, int pilesSize, int h) {
  int left = 1, right = 0;

  // find max pile
  for (int i = 0; i < pilesSize; i++) {
    if (piles[i] > right)
      right = piles[i];
  }

  int ans = right;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (canEat(piles, pilesSize, mid) <= h) {
      ans = mid;       // valid speed
      right = mid - 1; // try smaller
    } else {
      left = mid + 1; // need faster speed
    }
  }

  return ans;
}
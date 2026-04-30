#include <stdio.h>

int integerSqrt(int n) {
  int low = 0, high = n;
  int ans = 0;

  while (low <= high) {
    int mid = (low + high) / 2;

    // Avoid overflow using long long
    long long square = (long long)mid * mid;

    if (square == n) {
      return mid; // perfect square
    } else if (square < n) {
      ans = mid;     // store valid answer
      low = mid + 1; // go right
    } else {
      high = mid - 1; // go left
    }
  }

  return ans;
}

int main() {
  int n;
  scanf("%d", &n);

  int result = integerSqrt(n);
  printf("%d", result);

  return 0;
}
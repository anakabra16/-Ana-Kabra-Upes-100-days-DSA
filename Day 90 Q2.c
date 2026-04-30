#include <stdlib.h>

int canSplit(int *nums, int n, int k, int maxSum) {
  int count = 1;
  int currentSum = 0;

  for (int i = 0; i < n; i++) {
    if (currentSum + nums[i] > maxSum) {
      count++;
      currentSum = nums[i];
    } else {
      currentSum += nums[i];
    }
  }

  return count <= k;
}

int splitArray(int *nums, int numsSize, int k) {
  int left = 0, right = 0;

  // bounds
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] > left)
      left = nums[i];
    right += nums[i];
  }

  int ans = right;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (canSplit(nums, numsSize, k, mid)) {
      ans = mid;       // valid
      right = mid - 1; // try smaller
    } else {
      left = mid + 1; // need bigger
    }
  }

  return ans;
}
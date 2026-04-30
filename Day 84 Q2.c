int findPeakElement(int *nums, int numsSize) {
  int left = 0, right = numsSize - 1;

  while (left < right) {
    int mid = left + (right - left) / 2;

    if (nums[mid] < nums[mid + 1]) {
      left = mid + 1; // go right
    } else {
      right = mid; // go left
    }
  }

  return left; // or right (both same)
}
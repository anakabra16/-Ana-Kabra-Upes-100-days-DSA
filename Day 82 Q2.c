int searchInsert(int *nums, int numsSize, int target) {
  int left = 0, right = numsSize - 1;
  int ans = numsSize; // default position (insert at end)

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (nums[mid] >= target) {
      ans = mid;       // possible answer
      right = mid - 1; // move left
    } else {
      left = mid + 1;
    }
  }

  return ans;
}
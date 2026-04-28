int maxSubarraySumCircular(int *nums, int numsSize) {

  int total = 0;

  int maxSum = nums[0], currMax = 0;
  int minSum = nums[0], currMin = 0;

  for (int i = 0; i < numsSize; i++) {
    int x = nums[i];

    // Kadane for max
    currMax = (currMax > 0) ? currMax + x : x;
    if (currMax > maxSum)
      maxSum = currMax;

    // Kadane for min
    currMin = (currMin < 0) ? currMin + x : x;
    if (currMin < minSum)
      minSum = currMin;

    total += x;
  }

  // all negative case
  if (maxSum < 0)
    return maxSum;

  // return best of both cases
  if (maxSum > (total - minSum))
    return maxSum;
  else
    return total - minSum;
}
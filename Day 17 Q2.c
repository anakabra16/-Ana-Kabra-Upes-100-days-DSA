int maxSubArray(int *nums, int numsSize) {
  int maxSum = nums[0];
  int currentSum = nums[0];

  for (int i = 1; i < numsSize; i++) {

    // either take current element OR extend previous sum
    if (currentSum + nums[i] > nums[i])
      currentSum = currentSum + nums[i];
    else
      currentSum = nums[i];

    // update max
    if (currentSum > maxSum)
      maxSum = currentSum;
  }

  return maxSum;
}
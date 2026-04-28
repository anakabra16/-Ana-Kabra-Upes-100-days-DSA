int *productExceptSelf(int *nums, int numsSize, int *returnSize) {

  int *result = (int *)malloc(sizeof(int) * numsSize);

  // Step 1: store left products
  result[0] = 1;
  for (int i = 1; i < numsSize; i++) {
    result[i] = result[i - 1] * nums[i - 1];
  }

  // Step 2: multiply with right products
  int right = 1;
  for (int i = numsSize - 1; i >= 0; i--) {
    result[i] = result[i] * right;
    right *= nums[i];
  }

  *returnSize = numsSize;
  return result;
}
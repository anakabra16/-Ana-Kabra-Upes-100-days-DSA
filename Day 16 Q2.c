void reverse(int *nums, int start, int end) {
  while (start < end) {
    int temp = nums[start];
    nums[start] = nums[end];
    nums[end] = temp;

    start++;
    end--;
  }
}

void rotate(int *nums, int numsSize, int k) {
  k = k % numsSize; // handle large k

  // step 1: reverse whole array
  reverse(nums, 0, numsSize - 1);

  // step 2: reverse first k elements
  reverse(nums, 0, k - 1);

  // step 3: reverse remaining elements
  reverse(nums, k, numsSize - 1);
}
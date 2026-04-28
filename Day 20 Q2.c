#include <stdlib.h>

int compare(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int **threeSum(int *nums, int numsSize, int *returnSize,
               int **returnColumnSizes) {

  qsort(nums, numsSize, sizeof(int), compare);

  int maxSize = numsSize * numsSize; // safe upper bound

  int **result = (int **)malloc(sizeof(int *) * maxSize);
  *returnColumnSizes = (int *)malloc(sizeof(int) * maxSize);

  int k = 0;

  for (int i = 0; i < numsSize - 2; i++) {

    if (i > 0 && nums[i] == nums[i - 1])
      continue;

    int left = i + 1;
    int right = numsSize - 1;

    while (left < right) {
      int sum = nums[i] + nums[left] + nums[right];

      if (sum == 0) {
        result[k] = (int *)malloc(3 * sizeof(int));
        result[k][0] = nums[i];
        result[k][1] = nums[left];
        result[k][2] = nums[right];
        (*returnColumnSizes)[k] = 3;
        k++;

        left++;
        right--;

        while (left < right && nums[left] == nums[left - 1])
          left++;
        while (left < right && nums[right] == nums[right + 1])
          right--;

      } else if (sum < 0) {
        left++;
      } else {
        right--;
      }
    }
  }

  *returnSize = k;
  return result;
}
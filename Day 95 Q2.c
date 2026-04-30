#include <limits.h>
#include <stdlib.h>


int maximumGap(int *nums, int n) {
  if (n < 2)
    return 0;

  int min = INT_MAX, max = INT_MIN;

  for (int i = 0; i < n; i++) {
    if (nums[i] < min)
      min = nums[i];
    if (nums[i] > max)
      max = nums[i];
  }

  if (min == max)
    return 0;

  int gap = (max - min + n - 2) / (n - 1); // ceil
  int bucketCount = (max - min) / gap + 1;

  int *bucketMin = (int *)malloc(bucketCount * sizeof(int));
  int *bucketMax = (int *)malloc(bucketCount * sizeof(int));

  for (int i = 0; i < bucketCount; i++) {
    bucketMin[i] = INT_MAX;
    bucketMax[i] = INT_MIN;
  }

  // fill buckets
  for (int i = 0; i < n; i++) {
    int idx = (nums[i] - min) / gap;

    if (nums[i] < bucketMin[idx])
      bucketMin[idx] = nums[i];
    if (nums[i] > bucketMax[idx])
      bucketMax[idx] = nums[i];
  }

  // compute max gap
  int maxGap = 0;
  int prevMax = min;

  for (int i = 0; i < bucketCount; i++) {
    if (bucketMin[i] == INT_MAX)
      continue; // empty bucket

    int currGap = bucketMin[i] - prevMax;
    if (currGap > maxGap)
      maxGap = currGap;

    prevMax = bucketMax[i];
  }

  free(bucketMin);
  free(bucketMax);

  return maxGap;
}
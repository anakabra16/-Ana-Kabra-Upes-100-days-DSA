#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// 3-way partition Quickselect
int quickSelect(int *nums, int left, int right, int k) {
  while (left <= right) {
    int pivotIndex = left + rand() % (right - left + 1);
    int pivot = nums[pivotIndex];

    int low = left, mid = left, high = right;

    // Dutch National Flag partition
    while (mid <= high) {
      if (nums[mid] < pivot) {
        swap(&nums[low], &nums[mid]);
        low++;
        mid++;
      } else if (nums[mid] > pivot) {
        swap(&nums[mid], &nums[high]);
        high--;
      } else {
        mid++;
      }
    }

    // Now:
    // [left ... low-1] < pivot
    // [low ... high] = pivot
    // [high+1 ... right] > pivot

    if (k >= low && k <= high) {
      return nums[k]; // pivot region
    } else if (k < low) {
      right = low - 1;
    } else {
      left = high + 1;
    }
  }

  return -1;
}

int findKthLargest(int *nums, int numsSize, int k) {
  srand(time(NULL));
  int target = numsSize - k;
  return quickSelect(nums, 0, numsSize - 1, target);
}
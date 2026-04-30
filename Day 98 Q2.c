#include <stdlib.h>

int cmp(const void *a, const void *b) {
  int *x = *(int **)a;
  int *y = *(int **)b;
  return x[0] - y[0];
}

int **merge(int **intervals, int intervalsSize, int *intervalsColSize,
            int *returnSize, int **returnColumnSizes) {

  // Step 1: sort intervals
  qsort(intervals, intervalsSize, sizeof(int *), cmp);

  int **result = (int **)malloc(intervalsSize * sizeof(int *));
  *returnColumnSizes = (int *)malloc(intervalsSize * sizeof(int));

  int idx = 0;

  // Step 2: add first interval
  result[idx] = (int *)malloc(2 * sizeof(int));
  result[idx][0] = intervals[0][0];
  result[idx][1] = intervals[0][1];
  (*returnColumnSizes)[idx] = 2;

  idx++;

  // Step 3: merge
  for (int i = 1; i < intervalsSize; i++) {
    int start = intervals[i][0];
    int end = intervals[i][1];

    // overlap
    if (start <= result[idx - 1][1]) {
      if (end > result[idx - 1][1]) {
        result[idx - 1][1] = end;
      }
    } else {
      result[idx] = (int *)malloc(2 * sizeof(int));
      result[idx][0] = start;
      result[idx][1] = end;
      (*returnColumnSizes)[idx] = 2;
      idx++;
    }
  }

  *returnSize = idx;
  return result;
}
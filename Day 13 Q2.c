int *spiralOrder(int **matrix, int matrixSize, int *matrixColSize,
                 int *returnSize) {

  int m = matrixSize;
  int n = matrixColSize[0];

  int *result = (int *)malloc(sizeof(int) * (m * n));
  int k = 0;

  int top = 0, bottom = m - 1;
  int left = 0, right = n - 1;

  while (top <= bottom && left <= right) {

    // 1. left → right
    for (int i = left; i <= right; i++) {
      result[k++] = matrix[top][i];
    }
    top++;

    // 2. top → bottom
    for (int i = top; i <= bottom; i++) {
      result[k++] = matrix[i][right];
    }
    right--;

    // 3. right → left
    if (top <= bottom) {
      for (int i = right; i >= left; i--) {
        result[k++] = matrix[bottom][i];
      }
      bottom--;
    }

    // 4. bottom → top
    if (left <= right) {
      for (int i = bottom; i >= top; i--) {
        result[k++] = matrix[i][left];
      }
      left++;
    }
  }

  *returnSize = k;
  return result;
}
int **transpose(int **matrix, int matrixSize, int *matrixColSize,
                int *returnSize, int **returnColumnSizes) {

  int m = matrixSize;
  int n = matrixColSize[0];

  // result matrix will be n x m
  int **result = (int **)malloc(n * sizeof(int *));
  *returnColumnSizes = (int *)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++) {
    result[i] = (int *)malloc(m * sizeof(int));
    (*returnColumnSizes)[i] = m;
  }

  // transpose logic
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      result[j][i] = matrix[i][j];
    }
  }

  *returnSize = n;
  return result;
}
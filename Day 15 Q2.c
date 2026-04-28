void setZeroes(int **matrix, int matrixSize, int *matrixColSize) {
  int m = matrixSize;
  int n = matrixColSize[0];

  int row[m], col[n];

  // initialize
  for (int i = 0; i < m; i++)
    row[i] = 0;
  for (int j = 0; j < n; j++)
    col[j] = 0;

  // mark rows & cols
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (matrix[i][j] == 0) {
        row[i] = 1;
        col[j] = 1;
      }
    }
  }

  // apply zeros
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (row[i] == 1 || col[j] == 1) {
        matrix[i][j] = 0;
      }
    }
  }
}
class Solution {
  public boolean isToeplitzMatrix(int[][] matrix) {
    if (matrix.length == 0)
      return true;

    final int m = matrix.length;
    final int n = matrix[0].length;

    int[] buffer = new int[n];

    // load row[0] to buffer
    for (int j = 0; j < n; ++j)
      buffer[j] = matrix[0][j];

    // do rolling array
    for (int i = 1; i < m; ++i) {
      for (int j = 0; j + 1 < n; ++j)
        if (buffer[j] != matrix[i][j + 1])
          return false;
      buffer = matrix[i];
    }

    return true;
  }
}
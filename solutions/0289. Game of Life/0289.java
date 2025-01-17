class Solution {
  public void gameOfLife(int[][] board) {
    final int m = board.length;
    final int n = board[0].length;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        int ones = 0;
        for (int y = Math.max(0, i - 1); y < Math.min(m, i + 2); ++y)
          for (int x = Math.max(0, j - 1); x < Math.min(n, j + 2); ++x)
            ones += board[y][x] & 1;
        // any live cell with 2 or 3 live neighbors lives on to the next generation
        if (board[i][j] == 1 && (ones == 3 || ones == 4))
          board[i][j] |= 0b10;
        // any dead cell with exactly 3 live neighbors becomes a live cell, as if by reproduction
        if (board[i][j] == 0 && ones == 3)
          board[i][j] |= 0b10;
      }

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        board[i][j] >>= 1;
  }
}
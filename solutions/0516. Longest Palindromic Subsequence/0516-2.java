class Solution {
  public int longestPalindromeSubseq(String s) {
    final int n = s.length();

    // dp[i][j] := LPS's length in s[i..j]
    dp = new int[n][n];

    return lps(s, 0, n - 1);
  }

  private int[][] dp;

  private int lps(final String s, int i, int j) {
    if (i > j)
      return 0;
    if (i == j)
      return 1;
    if (dp[i][j] > 0)
      return dp[i][j];
    if (s.charAt(i) == s.charAt(j))
      return dp[i][j] = 2 + lps(s, i + 1, j - 1);

    return dp[i][j] = Math.max(lps(s, i + 1, j), lps(s, i, j - 1));
  }
}
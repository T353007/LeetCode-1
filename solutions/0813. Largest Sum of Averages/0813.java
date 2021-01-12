class Solution {
  public double largestSumOfAverages(int[] A, int K) {
    final int n = A.length;

    // dp[i][k] := largest score to partition first i nums into k groups
    double[][] dp = new double[n + 1][K + 1];
    double[] prefixSum = new double[n + 1];

    for (int i = 1; i <= n; ++i) {
      prefixSum[i] += prefixSum[i - 1] + A[i - 1];
      dp[i][1] = prefixSum[i] / i;
    }

    for (int k = 2; k <= K; ++k)
      for (int i = k; i <= n; ++i)
        for (int j = k - 1; j < i; ++j) {
          final double average = (prefixSum[i] - prefixSum[j]) / (i - j);
          dp[i][k] = Math.max(dp[i][k], dp[j][k - 1] + average);
        }

    return dp[n][K];
  }
}
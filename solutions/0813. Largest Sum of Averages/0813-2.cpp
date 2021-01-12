class Solution {
 public:
  double largestSumOfAverages(vector<int>& A, int K) {
    const int n = A.size();

    // dp[i][k] := largest score to partition first i nums into k groups
    dp = vector<vector<double>>(n + 1, vector<double>(K + 1));
    prefixSum = vector<double>(n + 1);

    for (int i = 1; i <= n; ++i)
      prefixSum[i] += prefixSum[i - 1] + A[i - 1];

    return largestSumOfAverages(A, n, K);
  }

 private:
  vector<vector<double>> dp;
  vector<double> prefixSum;

  double largestSumOfAverages(const vector<int>& A, int i, int k) {
    if (k == 1)
      return prefixSum[i] / i;
    if (dp[i][k])
      return dp[i][k];

    // try all possible partitions
    for (int j = k - 1; j < i; ++j)
      dp[i][k] = max(
          dp[i][k],
          largestSumOfAverages(A, j, k - 1) +
          (prefixSum[i] - prefixSum[j]) / (i - j));

    return dp[i][k];
  }
};
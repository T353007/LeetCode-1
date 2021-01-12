class Solution {
  public int splitArray(int[] nums, int m) {
    final int n = nums.length;

    // dp[i][k] := min of largest sum to split first i nums into k groups
    dp = new int[n + 1][m + 1];
    Arrays.stream(dp).forEach(row -> Arrays.fill(row, Integer.MAX_VALUE));

    // prefixSum[i] := sum of nums[0..i)
    prefixSum = new int[n + 1];

    for (int i = 1; i <= n; ++i)
      prefixSum[i] += prefixSum[i - 1] + nums[i - 1];

    return splitArray(nums, n, m);
  }

  private int[][] dp;
  private int[] prefixSum;

  private int splitArray(int[] nums, int i, int k) {
    if (k == 1)
      return prefixSum[i];
    if (dp[i][k] < Integer.MAX_VALUE)
      return dp[i][k];

    // try all possible partitions
    for (int j = k - 1; j < i; ++j)
      dp[i][k] = Math.min(
          dp[i][k],
          Math.max(splitArray(nums, j, k - 1), prefixSum[i] - prefixSum[j]));

    return dp[i][k];
  }
}
class Solution {
 public:
  int splitArray(vector<int>& nums, int m) {
    const int n = nums.size();

    // dp[i][k] := min of largest sum to split first i nums into k groups
    dp = vector<vector<int>>(n + 1, vector<int>(m + 1, INT_MAX));

    // prefixSum[i] := sum of nums[0..i)
    prefixSum = vector<int>(n + 1);

    for (int i = 1; i <= n; ++i)
      prefixSum[i] += prefixSum[i - 1] + nums[i - 1];

    return splitArray(nums, n, m);
  }

 private:
  vector<vector<int>> dp;
  vector<int> prefixSum;

  int splitArray(const vector<int>& nums, int i, int k) {
    if (k == 1)
      return prefixSum[i];
    if (dp[i][k] < INT_MAX)
      return dp[i][k];

    // try all possible partitions
    for (int j = k - 1; j < i; ++j)
      dp[i][k] = min(dp[i][k], max(splitArray(nums, j, k - 1),
                                   prefixSum[i] - prefixSum[j]));

    return dp[i][k];
  }
};
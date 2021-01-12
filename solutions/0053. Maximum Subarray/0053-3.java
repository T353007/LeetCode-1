class Solution {
  public int maxSubArray(int[] nums) {
    final int n = nums.length;

    // dp[i] := max sum subarray ending w/ nums[i]
    int[] dp = new int[n];
    dp[0] = nums[0];

    for (int i = 1; i < n; ++i)
      dp[i] = (dp[i - 1] > 0 ? dp[i - 1] : 0) + nums[i];

    return Arrays.stream(dp).max().getAsInt();
  }
}
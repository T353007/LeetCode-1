class Solution {
 public:
  int numWays(int steps, int arrLen) {
    constexpr int kMod = 1e9 + 7;
    const int n = min(arrLen, steps / 2 + 1);

    vector<long> dp(n);  // dp[i] := # of ways to stay on index i
    dp[0] = 1;

    while (steps--) {
      vector<long> newDp(n);
      for (int i = 0; i < n; ++i) {
        newDp[i] = dp[i];
        if (i - 1 >= 0)
          newDp[i] += dp[i - 1];
        if (i + 1 < n)
          newDp[i] += dp[i + 1];
        newDp[i] %= kMod;
      }
      dp = move(newDp);
    }

    return dp[0];
  }
};
class Solution {
 public:
  int numPermsDISequence(string S) {
    constexpr int kMod = 1e9 + 7;
    const int n = S.length();

    vector<int> dp(n + 1);

    // when there's only one digit, the # of perms is 1
    for (int j = 0; j <= n; ++j)
      dp[j] = 1;

    for (int i = 1; i <= n; ++i) {
      vector<int> newDp(n + 1);
      if (S[i - 1] == 'I') {  // S[i - 1] == 'I'
        // calculate postfix sum to prevent duplicate calculation
        int postfixSum = 0;
        for (int j = n - i; j >= 0; --j) {
          postfixSum = (postfixSum + dp[j + 1]) % kMod;
          newDp[j] = postfixSum;
        }
      } else {  // S[i - 1] == 'D'
        // calculate prefix sum to prevent duplicate calculation
        int prefixSum = 0;
        for (int j = 0; j <= n - i; ++j) {
          prefixSum = (prefixSum + dp[j]) % kMod;
          newDp[j] = prefixSum;
        }
      }
      dp = move(newDp);
    }

    return dp[0];
  }
};
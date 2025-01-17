class Solution {
 public:
  int numPermsDISequence(string S) {
    constexpr int kMod = 1e9 + 7;
    const int n = S.length();

    // dp[i][j] := # of valid permutations w/ i + 1 digits, where s[i] is j-th
    // digit of remaining digits
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));

    // when there's only one digit, the # of perms is 1
    for (int j = 0; j <= n; ++j)
      dp[0][j] = 1;

    for (int i = 1; i <= n; ++i)
      if (S[i - 1] == 'I') {  // S[i - 1] == 'I'
        // calculate postfix sum to prevent duplicate calculation
        int postfixSum = 0;
        for (int j = n - i; j >= 0; --j) {
          postfixSum = (postfixSum + dp[i - 1][j + 1]) % kMod;
          dp[i][j] = postfixSum;
        }
      } else {  // S[i - 1] == 'D'
        // calculate prefix sum to prevent duplicate calculation
        int prefixSum = 0;
        for (int j = 0; j <= n - i; ++j) {
          prefixSum = (prefixSum + dp[i - 1][j]) % kMod;
          dp[i][j] = prefixSum;
        }
      }

    return dp[n][0];
  }
};
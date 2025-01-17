typedef vector<vector<vector<int>>> VVV;
typedef vector<vector<int>> VV;
typedef vector<int> V;

class Solution {
 public:
  int profitableSchemes(int n, int minProfit, vector<int>& group,
                        vector<int>& profit) {
    constexpr int kMod = 1e9 + 7;

    // dp[k][i][j] := # of schemes w/ first k crimes, AT MOST i members, and at
    // least j profits
    VVV dp(group.size() + 1, VV(n + 1, V(minProfit + 1)));

    // no crimes, no profits, and any # of members
    for (int i = 0; i <= n; ++i)
      dp[0][i][0] = 1;

    for (int k = 1; k <= group.size(); ++k) {
      const int g = group[k - 1];
      const int p = profit[k - 1];
      for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= minProfit; ++j)
          if (i < g)
            dp[k][i][j] = dp[k - 1][i][j];
          else
            dp[k][i][j] = (dp[k - 1][i][j] + dp[k - 1][i - g][max(0, j - p)]) % kMod;
    }

    return dp[group.size()][n][minProfit];
  }
};
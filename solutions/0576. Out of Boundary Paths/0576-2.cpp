typedef vector<vector<vector<int>>> VVV;
typedef vector<vector<int>> VV;
typedef vector<int> V;

class Solution {
 public:
  int findPaths(int m, int n, int N, int i, int j) {
    this->m = m;
    this->n = n;

    dp = VVV(N + 1, VV(m, V(n, -1)));

    return findPaths(N, i, j);
  }

 private:
  constexpr static int kMod = 1e9 + 7;
  int m;
  int n;

  // dp[k][i][j] := # of paths to move the ball (i, j) out of bound with k moves
  VVV dp;

  int findPaths(int k, int i, int j) {
    if (i < 0 || i == m || j < 0 || j == n)
      return 1;
    if (k == 0)
      return 0;
    if (dp[k][i][j] != -1)
      return dp[k][i][j];

    return dp[k][i][j] =
      ((findPaths(k - 1, i + 1, j) + findPaths(k - 1, i - 1, j)) % kMod +
       (findPaths(k - 1, i, j + 1) + findPaths(k - 1, i, j - 1)) % kMod) %
        kMod;
  }
};
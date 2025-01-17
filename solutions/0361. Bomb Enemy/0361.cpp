class Solution {
 public:
  int maxKilledEnemies(vector<vector<char>>& grid) {
    if (grid.empty() || grid[0].empty())
      return 0;

    const int m = grid.size();
    const int n = grid[0].size();

    int ans = 0;
    int enemyCount = 0;
    // dp[i][j] := max enemies grid[i][j] can kill
    vector<vector<int>> dp(m, vector<int>(n));

    auto update = [&](int i, int j) {
      if (grid[i][j] == '0')
        dp[i][j] += enemyCount;
      else if (grid[i][j] == 'E')
        ++enemyCount;
      else  // grid[i][j] == 'W'
        enemyCount = 0;
    };

    // extend four directions, if meet 'W', need to start over from 0
    for (int i = 0; i < m; ++i) {
      enemyCount = 0;
      for (int j = 0; j < n; ++j)
        update(i, j);
      enemyCount = 0;
      for (int j = n - 1; j >= 0; --j)
        update(i, j);
    }

    for (int j = 0; j < n; ++j) {
      enemyCount = 0;
      for (int i = 0; i < m; ++i)
        update(i, j);
      enemyCount = 0;
      for (int i = m - 1; i >= 0; --i)
        update(i, j);
    }

    for (const vector<int>& row : dp)
      ans = max(ans, *max_element(begin(row), end(row)));

    return ans;
  }
};
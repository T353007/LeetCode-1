class Solution {
 public:
  string findShortestWay(vector<vector<int>>& maze, vector<int>& ball,
                         vector<int>& hole) {
    string ans = "impossible";
    int minSteps = INT_MAX;

    dfs(maze, ball[0], ball[1], hole, 0, 0, 0, minSteps, "", ans);

    return ans;
  }

 private:
  void dfs(vector<vector<int>>& maze, int i, int j, const vector<int>& hole,
           int dx, int dy, int steps, int& minSteps, const string& path,
           string& ans) {
    if (steps >= minSteps)
      return;

    if (dx != 0 || dy != 0) {  // both are zero for the initial ball position
      while (i + dx >= 0 && i + dx < maze.size() && j + dy >= 0 &&
             j + dy < maze[0].size() && maze[i + dx][j + dy] != 1) {
        i += dx;
        j += dy;
        ++steps;
        if (i == hole[0] && j == hole[1] && steps < minSteps) {
          minSteps = steps;
          ans = path;
        }
      }
    }

    if (maze[i][j] == 0 || steps + 2 < maze[i][j]) {
      maze[i][j] = steps + 2;  // +2 to because of maze[i][j] == 0 || 1
      if (dx == 0)
        dfs(maze, i, j, hole, 1, 0, steps, minSteps, path + "d", ans);
      if (dy == 0)
        dfs(maze, i, j, hole, 0, -1, steps, minSteps, path + "l", ans);
      if (dy == 0)
        dfs(maze, i, j, hole, 0, 1, steps, minSteps, path + "r", ans);
      if (dx == 0)
        dfs(maze, i, j, hole, -1, 0, steps, minSteps, path + "u", ans);
    }
  }
};
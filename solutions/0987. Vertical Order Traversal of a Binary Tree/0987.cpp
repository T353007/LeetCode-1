class Solution {
 public:
  vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> ans;
    map<int, set<pair<int, int>>> xToSortedPairs;  // {x: {(-y, val)}}

    dfs(root, 0, 0, xToSortedPairs);

    for (const auto& [_, pairs] : xToSortedPairs) {
      vector<int> vals;
      for (const auto& pair : pairs)
        vals.push_back(pair.second);
      ans.push_back(vals);
    }

    return ans;
  }

 private:
  void dfs(TreeNode* root, int x, int y,
           map<int, set<pair<int, int>>>& xToSortedPairs) {
    if (!root)
      return;

    xToSortedPairs[x].insert({y, root->val});
    dfs(root->left, x - 1, y + 1, xToSortedPairs);
    dfs(root->right, x + 1, y + 1, xToSortedPairs);
  }
};
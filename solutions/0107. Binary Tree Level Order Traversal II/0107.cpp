class Solution {
 public:
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    if (!root)
      return {};

    vector<vector<int>> ans;
    queue<TreeNode*> q{{root}};

    while (!q.empty()) {
      vector<int> currLevel;
      for (int size = q.size(); size > 0; --size) {
        TreeNode* node = q.front();
        q.pop();
        currLevel.push_back(node->val);
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
      ans.push_back(currLevel);
    }

    reverse(begin(ans), end(ans));
    return ans;
  }
};
class Solution {
 public:
  int widthOfBinaryTree(TreeNode* root) {
    if (!root)
      return 0;

    int ans = 0;
    queue<pair<TreeNode*, int>> q{{{root, 1}}};  // {node, index}

    while (!q.empty()) {
      const int offset = q.front().second * 2;
      ans = max(ans, q.back().second - q.front().second + 1);
      for (int size = q.size(); size > 0; --size) {
        const auto [node, index] = q.front();
        q.pop();
        if (node->left)
          q.push({node->left, index * 2 - offset});
        if (node->right)
          q.push({node->right, index * 2 + 1 - offset});
      }
    }

    return ans;
  }
};
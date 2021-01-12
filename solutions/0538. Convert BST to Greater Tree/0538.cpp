class Solution {
 public:
  TreeNode* convertBST(TreeNode* root) {
    int prefixSum = 0;

    reversedInorder(root, prefixSum);

    return root;
  }

 private:
  void reversedInorder(TreeNode* root, int& prefixSum) {
    if (!root)
      return;

    reversedInorder(root->right, prefixSum);
    prefixSum += root->val;
    root->val = prefixSum;
    reversedInorder(root->left, prefixSum);
  }
};
class Solution {
  public TreeNode convertBST(TreeNode root) {
    reversedInorder(root);
    return root;
  }

  private int prefixSum = 0;

  private void reversedInorder(TreeNode root) {
    if (root == null)
      return;

    reversedInorder(root.right);
    prefixSum += root.val;
    root.val = prefixSum;
    reversedInorder(root.left);
  }
}
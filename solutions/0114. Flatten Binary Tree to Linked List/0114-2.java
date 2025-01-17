class Solution {
  public void flatten(TreeNode root) {
    if (root == null)
      return;

    Stack<TreeNode> stack = new Stack<>();
    stack.push(root);

    while (!stack.isEmpty()) {
      root = stack.pop();
      if (root.right != null)
        stack.push(root.right);
      if (root.left != null)
        stack.push(root.left);
      if (!stack.isEmpty())
        root.right = stack.peek();
      root.left = null;
    }
  }
}
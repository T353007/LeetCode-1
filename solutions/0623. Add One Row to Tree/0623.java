class Solution {
  public TreeNode addOneRow(TreeNode root, int v, int d) {
    if (d == 1) {
      TreeNode newRoot = new TreeNode(v);
      newRoot.left = root;
      return newRoot;
    }

    int depth = 0;
    Queue<TreeNode> q = new LinkedList<>(Arrays.asList(root));

    while (!q.isEmpty()) {
      ++depth;
      for (int size = q.size(); size > 0; --size) {
        TreeNode node = q.poll();
        if (node.left != null)
          q.offer(node.left);
        if (node.right != null)
          q.offer(node.right);
        if (depth == d - 1) {
          TreeNode cachedLeft = node.left;
          TreeNode cachedRight = node.right;
          node.left = new TreeNode(v);
          node.right = new TreeNode(v);
          node.left.left = cachedLeft;
          node.right.right = cachedRight;
        }
      }
      if (depth == d - 1)
        break;
    }

    return root;
  }
}
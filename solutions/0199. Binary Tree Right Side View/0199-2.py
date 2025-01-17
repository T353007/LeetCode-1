class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        ans = []

        def dfs(root: TreeNode, depth: int) -> None:
            if not root:
                return

            if depth == len(ans):
                ans.append(root.val)
            dfs(root.right, depth + 1)
            dfs(root.left, depth + 1)

        dfs(root, 0)

        return ans

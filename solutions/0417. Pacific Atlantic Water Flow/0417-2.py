class Solution:
    def pacificAtlantic(self, matrix: List[List[int]]) -> List[List[int]]:
        if not matrix:
            return []

        m = len(matrix)
        n = len(matrix[0])

        ans = []
        seenP = [[False] * n for _ in range(m)]
        seenA = [[False] * n for _ in range(m)]

        def dfs(i: int, j: int, h: int, seen: List[List[bool]]) -> None:
            if i < 0 or i == m or j < 0 or j == n:
                return
            if seen[i][j] or matrix[i][j] < h:
                return

            seen[i][j] = True
            dfs(i + 1, j, matrix[i][j], seen)
            dfs(i - 1, j, matrix[i][j], seen)
            dfs(i, j + 1, matrix[i][j], seen)
            dfs(i, j - 1, matrix[i][j], seen)

        for i in range(m):
            dfs(i, 0, 0, seenP)
            dfs(i, n - 1, 0, seenA)

        for j in range(n):
            dfs(0, j, 0, seenP)
            dfs(m - 1, j, 0, seenA)

        return [[i, j] for i in range(m) for j in range(n) if seenP[i][j] and seenA[i][j]]

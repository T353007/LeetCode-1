class Solution:
    def canCross(self, stones: List[int]) -> bool:
        n = len(stones)

        # dp[i][j] := True if a frog can jumps to stones[i] with j units
        dp = [[False] * (n + 1) for _ in range(n)]
        dp[0][1] = True

        for i in range(1, n):
            for j in range(i):
                k = stones[i] - stones[j]
                if k <= n and dp[j][k]:
                    dp[i][k - 1] = True
                    dp[i][k] = True
                    dp[i][k + 1] = True

        return any(dp[-1])

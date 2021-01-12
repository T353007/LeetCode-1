class Solution:
    def numDecodings(self, s: str) -> int:
        n = len(s)

        # dp[i] := # of ways to decode s[i..n)
        dp = [0] * n + [1]
        if self.isValid(s[n - 1]):
            dp[n - 1] = 1

        for i in range(n - 2, -1, -1):
            if self.isValid(s[i]):
                dp[i] += dp[i + 1]
            if self.isValid(s[i], s[i + 1]):
                dp[i] += dp[i + 2]

        return dp[0]

    def isValid(self, a: chr, b=None) -> bool:
        if b:
            return a == '1' or (a == '2' and b <= '6')
        return a != '0'

class Solution:
    def numTrees(self, n: int) -> int:
        G = [0] * (n + 1)  # G[i] := # of unique BST's that store values 1..i
        G[0] = 1
        G[1] = 1

        for i in range(2, n + 1):
            for j in range(i):
                G[i] += G[j] * G[i - j - 1]

        return G[n]

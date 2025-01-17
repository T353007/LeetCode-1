class Solution:
    def findMinStep(self, board: str, hand: str) -> int:
        def deDup(board):
            start = 0  # start index of a color sequenece
            for i, c in enumerate(board):
                if c != board[start]:
                    if i - start >= 3:
                        return deDup(board[:start] + board[i:])
                    start = i  # meet a new sequence
            return board

        @lru_cache(None)
        def dfs(board: str, hand: str):
            board = deDup(board)
            if board == '#':
                return 0

            boardSet = set(board)
            # hand that in board
            hand = ''.join(h for h in hand if h in boardSet)
            if not hand:  # infeasible
                return float('inf')

            ans = float('inf')

            for i in range(len(board)):
                for j, h in enumerate(hand):
                    # place hs[j] in board[i]
                    newHand = hand[:j] + hand[j + 1:]
                    newBoard = board[:i] + h + board[i:]
                    ans = min(ans, 1 + dfs(newBoard, newHand))

            return ans

        ans = dfs(board + '#', hand)
        return -1 if ans == float('inf') else ans

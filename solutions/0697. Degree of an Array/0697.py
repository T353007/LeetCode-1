class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        ans = 0
        degree = 0
        debut = {}
        count = Counter()

        for i, num in enumerate(nums):
            if num not in debut:
                debut[num] = i
            count[num] += 1
            if count[num] > degree:
                degree = count[num]
                ans = i - debut[num] + 1
            elif count[num] == degree:
                ans = min(ans, i - debut[num] + 1)

        return ans

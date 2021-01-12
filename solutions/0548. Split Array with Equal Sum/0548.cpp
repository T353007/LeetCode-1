class Solution {
 public:
  bool splitArray(vector<int>& nums) {
    const int n = nums.size();
    if (n < 7)
      return false;

    vector<int> prefixSum(n);

    for (int i = 0; i < n; ++i)
      prefixSum[i] = i == 0 ? nums[0] : prefixSum[i - 1] + nums[i];

    for (int j = 3; j < n - 3; ++j) {
      unordered_set<int> seen;
      for (int i = 1; i < j - 1; ++i)
        if (prefixSum[i - 1] == prefixSum[j - 1] - prefixSum[i])
          seen.insert(prefixSum[i - 1]);
      for (int k = j + 2; k < n - 1; ++k)
        if (prefixSum[n - 1] - prefixSum[k] ==
                prefixSum[k - 1] - prefixSum[j] &&
            seen.count(prefixSum[k - 1] - prefixSum[j]))
          return true;
    }

    return false;
  }
};
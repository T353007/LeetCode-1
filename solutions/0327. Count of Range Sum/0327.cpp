class Solution {
 public:
  int countRangeSum(vector<int>& nums, int lower, int upper) {
    const int n = nums.size();

    int count = 0;
    vector<long> prefixSum(n + 1);

    for (int i = 1; i <= n; ++i)
      prefixSum[i] += prefixSum[i - 1] + (long)nums[i - 1];

    mergeSort(prefixSum, 0, n, lower, upper, count);

    return count;
  }

 private:
  void mergeSort(vector<long>& prefixSum, int l, int r, int lower, int upper,
                 int& count) {
    if (l >= r)
      return;

    const int m = l + (r - l) / 2;
    mergeSort(prefixSum, l, m, lower, upper, count);
    mergeSort(prefixSum, m + 1, r, lower, upper, count);
    merge(prefixSum, l, m, r, lower, upper, count);
  }

  void merge(vector<long>& prefixSum, int l, int m, int r, int lower, int upper,
             int& count) {
    int lo = m + 1;  // 1st index s.t. prefixSum[lo] - prefixSum[i] >= lower
    int hi = m + 1;  // 1st index s.t. prefixSum[hi] - prefixSum[i] > upper

    // for each index i in range [l, m], add hi - lo to count
    for (int i = l; i <= m; ++i) {
      while (lo <= r && prefixSum[lo] - prefixSum[i] < lower)
        ++lo;
      while (hi <= r && prefixSum[hi] - prefixSum[i] <= upper)
        ++hi;
      count += hi - lo;
    }

    vector<long> sorted(r - l + 1);
    int k = 0;      // sorted's pointer
    int i = l;      // left's pointer
    int j = m + 1;  // right's pointer

    while (i <= m && j <= r)
      if (prefixSum[i] < prefixSum[j])
        sorted[k++] = prefixSum[i++];
      else
        sorted[k++] = prefixSum[j++];

    // put possible remaining left part to the sorted array
    while (i <= m)
      sorted[k++] = prefixSum[i++];

    // put possible remaining right part to the sorted array
    while (j <= r)
      sorted[k++] = prefixSum[j++];

    copy(begin(sorted), end(sorted), begin(prefixSum) + l);
  }
};
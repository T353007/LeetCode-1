class Solution {
  public int missingElement(int[] nums, int k) {
    int l = 0;
    int r = nums.length;

    // find the first index l s.t. nMissing(l) >= k
    while (l < r) {
      final int m = l + (r - l) / 2;
      if (nMissing(nums, m) >= k)
        r = m;
      else
        l = m + 1;
    }

    return nums[l - 1] + (k - nMissing(nums, l - 1));
  }

  // # of missing numbers in [nums[0], nums[i]]
  private int nMissing(int[] nums, int i) {
    return nums[i] - nums[0] - i;
  }
}
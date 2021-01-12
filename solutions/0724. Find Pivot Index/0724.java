class Solution {
  public int pivotIndex(int[] nums) {
    final int sum = Arrays.stream(nums).sum();
    int prefixSum = 0;

    for (int i = 0; i < nums.length; ++i) {
      if (prefixSum == sum - prefixSum - nums[i])
        return i;
      prefixSum += nums[i];
    }

    return -1;
  }
}
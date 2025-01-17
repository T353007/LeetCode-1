class Solution {
  public int wiggleMaxLength(int[] nums) {
    if (nums.length == 0)
      return 0;

    int increasing = 1;
    int decreasing = 1;

    for (int i = 1; i < nums.length; ++i)
      if (nums[i] > nums[i - 1])
        increasing = decreasing + 1;
      else if (nums[i] < nums[i - 1])
        decreasing = increasing + 1;

    return Math.max(increasing, decreasing);
  }
}
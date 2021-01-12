class Solution {
 public:
  int arrayNesting(vector<int>& nums) {
    int ans = 0;

    for (const int num : nums) {
      if (num == -1)
        continue;
      int index = num;
      int count = 0;
      while (nums[index] != -1) {  // not yet seen
        const int cache = index;
        index = nums[index];  // get next index
        nums[cache] = -1;     // already seen
        ++count;
      }
      ans = max(ans, count);
    }

    return ans;
  }
};
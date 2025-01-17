/*
https://leetcode.com/problems/median-of-two-sorted-arrays/

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

Follow up: The overall run time complexity should be O(log (m+n)).


Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
Example 3:

Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000
Example 4:

Input: nums1 = [], nums2 = [1]
Output: 1.00000
Example 5:

Input: nums1 = [2], nums2 = []
Output: 2.00000
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106

*/
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        
        int total = nums1.length + nums2.length;
        double median = Math.ceil((double) total / 2);
        
        Queue<Double> pq = new PriorityQueue(); 
        
        for(int num : nums1) {
            pq.add((double) num);
        }
        
        for(int num : nums2) {
            pq.add((double) num);
        }
        
        for(int i = 0; i < median - 1 ; i++) {
            pq.poll();
        }
        
        return total % 2.0 == 0.0 ? ( (pq.poll() +  pq.poll()) / 2.0 ) : pq.poll();
    }
}



 public double findMedianSortedArraysBinarySearch(int[] nums1, int[] nums2) {
    final int n1 = nums1.length;
    final int n2 = nums2.length;

    if (n1 > n2)
      return findMedianSortedArraysBinarySearch(nums2, nums1);

    int l = 0;
    int r = n1;

    while (l <= r) {
      final int partition1 = l + (r - l) / 2;
      final int partition2 = (n1 + n2 + 1) / 2 - partition1;
      final int maxLeft1 = partition1 == 0 ? Integer.MIN_VALUE : nums1[partition1 - 1];
      final int maxLeft2 = partition2 == 0 ? Integer.MIN_VALUE : nums2[partition2 - 1];
      final int minRight1 = partition1 == n1 ? Integer.MAX_VALUE : nums1[partition1];
      final int minRight2 = partition2 == n2 ? Integer.MAX_VALUE : nums2[partition2];
      if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1)
        return (n1 + n2) % 2 == 0 ? (Math.max(maxLeft1, maxLeft2) + Math.min(minRight1, minRight2)) * 0.5
            : Math.max(maxLeft1, maxLeft2);
      else if (maxLeft1 > minRight2)
        r = partition1 - 1;
      else
        l = partition1 + 1;
    }
  
   thrown new IllegalArgumentException("bad input");
 }

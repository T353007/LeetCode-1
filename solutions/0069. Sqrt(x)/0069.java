class Solution {
  public int mySqrt(long x) {
    long l = 1;
    long r = x + 1;

    while (l < r) {
      final long m = l + (r - l) / 2;
      if (m > x / m)
        r = m;
      else
        l = m + 1;
    }

    // l: smallest number s.t. l * l > x
    return (int) l - 1;
  }
}
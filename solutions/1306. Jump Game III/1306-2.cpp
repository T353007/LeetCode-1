class Solution {
 public:
  bool canReach(vector<int>& arr, int start) {
    vector<bool> seen(arr.size());
    return canReach(arr, start, seen);
  }

 private:
  bool canReach(const vector<int>& A, int node, vector<bool>& seen) {
    if (node < 0 || node >= A.size())
      return false;
    if (seen[node])
      return false;
    if (A[node] == 0)
      return true;

    seen[node] = true;

    return canReach(A, node + A[node], seen) ||
           canReach(A, node - A[node], seen);
  }
};
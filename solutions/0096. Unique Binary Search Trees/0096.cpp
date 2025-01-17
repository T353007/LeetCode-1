class Solution {
 public:
  int numTrees(int n) {
    vector<int> G(n + 1);  // G[i] := # of unique BST's that store values 1..i
    G[0] = 1;
    G[1] = 1;

    for (int i = 2; i <= n; ++i)
      for (int j = 0; j < i; ++j)
        G[i] += G[j] * G[i - j - 1];

    return G[n];
  }
};
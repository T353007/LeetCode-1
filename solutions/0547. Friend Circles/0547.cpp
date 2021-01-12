class UF {
 public:
  UF(int n) : size(n), parent(n) {
    for (int i = 0; i < n; ++i)
      parent[i] = i;
  }

  void union_(int u, int v) {
    const int pu = find(u);
    const int pv = find(v);
    if (pu == pv)
      return;

    parent[pu] = pv;
    --size;
  }

  int getSize() {
    return size;
  }

 private:
  int size;
  vector<int> parent;

  int find(int u) {
    if (u != parent[u])
      parent[u] = find(parent[u]);
    return parent[u];
  }
};

class Solution {
 public:
  int findCircleNum(vector<vector<int>>& M) {
    const int n = M.size();

    UF uf(n);

    for (int i = 0; i < n; ++i)
      for (int j = i; j < n; ++j)
        if (M[i][j] == 1)
          uf.union_(i, j);

    return uf.getSize();
  }
};
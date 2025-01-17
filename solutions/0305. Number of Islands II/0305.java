class UF {
  public int[] parent;

  public UF(int n) {
    parent = new int[n];
    Arrays.fill(parent, -1); // water
  }

  public void union(int pu, int pv) {
    parent[pu] = pv;
  }

  public int find(int u) {
    if (u != parent[u])
      u = find(parent[u]);
    return parent[u];
  }
}

class Solution {
  public List<Integer> numIslands2(int m, int n, int[][] positions) {
    final int[] dirs = { 0, 1, 0, -1, 0 };
    List<Integer> ans = new ArrayList<>();
    boolean[][] seen = new boolean[m][n];
    UF uf = new UF(m * n);
    int count = 0;

    for (int[] p : positions) {
      final int i = p[0];
      final int j = p[1];
      if (seen[i][j]) {
        ans.add(count);
        continue;
      }
      seen[i][j] = true;
      final int id = getId(i, j, n);
      uf.parent[id] = id;
      ++count;
      for (int k = 0; k < 4; ++k) {
        final int x = i + dirs[k];
        final int y = j + dirs[k + 1];
        if (x < 0 || x == m || y < 0 || y == n)
          continue;
        final int neighborId = getId(x, y, n);
        if (uf.parent[neighborId] == -1) // water
          continue;
        final int currentParent = uf.find(id);
        final int neighborParent = uf.find(neighborId);
        if (currentParent != neighborParent) {
          uf.union(currentParent, neighborParent);
          --count;
        }
      }
      ans.add(count);
    }

    return ans;
  }

  private int getId(int i, int j, int n) {
    return i * n + j;
  }
}
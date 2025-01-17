class Solution {
  public int[] sortItems(int n, int m, int[] group, List<List<Integer>> beforeItems) {
    List<Integer>[] graph = new List[n + m];
    int[] inDegree = new int[n + m];

    for (int i = 0; i < graph.length; ++i)
      graph[i] = new ArrayList<>();

    // build graph by remapping k-th group to k + n imaginary node
    for (int i = 0; i < group.length; ++i) {
      if (group[i] == -1)
        continue;
      graph[group[i] + n].add(i);
      ++inDegree[i];
    }

    for (int i = 0; i < beforeItems.size(); ++i)
      for (final int b : beforeItems.get(i)) {
        final int out = group[b] == -1 ? b : group[b] + n;
        final int in = group[i] == -1 ? i : group[i] + n;
        if (out == in) { // already in the same group
          graph[b].add(i);
          ++inDegree[i];
        } else {
          graph[out].add(in);
          ++inDegree[in];
        }
      }

    // topology
    List<Integer> ans = new ArrayList<>();

    for (int i = 0; i < n + m; ++i)
      if (inDegree[i] == 0) // inDegree[i] == -1 means visited
        dfs(graph, i, inDegree, n, ans);

    return ans.size() == n ? ans.stream().mapToInt(i -> i).toArray() : new int[] {};
  }

  private void dfs(List<Integer>[] graph, int out, int[] inDegree, int n, List<Integer> ans) {
    if (out < n)
      ans.add(out);

    inDegree[out] = -1; // mark as visited

    for (final int in : graph[out])
      if (--inDegree[in] == 0)
        dfs(graph, in, inDegree, n, ans);
  }
}
class Solution {
 public:
  string removeDuplicates(const string& s, int k) {
    string ans;
    vector<pair<char, int>> stack;

    for (const char c : s)
      if (stack.empty() || stack.back().first != c)
        stack.push_back({c, 1});
      else if (++stack.back().second == k)  // stack.back() == c
        stack.pop_back();

    for (const auto& [c, count] : stack)
      ans.append(count, c);

    return ans;
  }
};
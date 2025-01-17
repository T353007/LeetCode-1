class T {
  public int depth;
  public int length;

  public T(int depth, int length) {
    this.depth = depth;
    this.length = length;
  }
}

class Solution {
  public int lengthLongestPath(String input) {
    int ans = 0;
    Stack<T> stack = new Stack<>();
    stack.push(new T(-1, 0));

    for (String token : input.split("\n")) {
      final int depth = getDepth(token);
      token = token.replace("\t", "");
      while (depth <= stack.peek().depth)
        stack.pop();
      if (token.contains(".")) // file
        ans = Math.max(ans, stack.peek().length + token.length());
      else // directory + '/'
        stack.push(new T(depth, stack.peek().length + token.length() + 1));
    }

    return ans;
  }

  private int getDepth(final String token) {
    return (int) token.chars().filter(c -> c == '\t').count();
  }
}
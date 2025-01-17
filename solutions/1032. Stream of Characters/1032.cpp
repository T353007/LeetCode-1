struct TrieNode {
  TrieNode() : children(26), isWord(false) {
  }
  ~TrieNode() {
    for (TrieNode* child : children)
      delete child;
  }
  vector<TrieNode*> children;
  bool isWord;
};

class StreamChecker {
 public:
  StreamChecker(vector<string>& words) {
    for (const string& word : words)
      insert(word);
  }

  bool query(char letter) {
    letters += letter;
    TrieNode* node = &root;

    for (int i = letters.length() - 1; i >= 0; --i) {
      const int index = letters[i] - 'a';
      if (!node->children[index])
        return false;
      node = node->children[index];
      if (node->isWord)
        return true;
    }

    return false;
  }

 private:
  string letters;
  TrieNode root;

  void insert(const string& word) {
    TrieNode* node = &root;
    for (int i = word.length() - 1; i >= 0; --i) {
      const int index = word[i] - 'a';
      if (!node->children[index])
        node->children[index] = new TrieNode;
      node = node->children[index];
    }
    node->isWord = true;
  }
};
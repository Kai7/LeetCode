#include "utils/data_structure.hpp"

class WordDictionary {
public:
  /* 91.51, 85.95 */
  class TrieNode {
  public:
    bool isWord;
    TrieNode *child[26];
    TrieNode() : isWord(false) {
      for (TrieNode*& p: child) {
        p = nullptr;
      }
    }
  };

  TrieNode *root;
  WordDictionary() {
    root = new TrieNode();
  }
  
  void addWord(string word) {
    TrieNode* p = root;
    for (auto& c: word) {
      int idx = c - 'a';
      if (p->child[idx] == nullptr) {
        p->child[idx] = new TrieNode();
      }
      p = p->child[idx];
    }
    p->isWord = true;
  }
  
  bool search(string word) {
    return search_helper(word, 0, root);
  }

  bool search_helper(string& word, int i, TrieNode* p) {
    if (i >= word.size()) {
      return p->isWord;
    }
    if (word[i] != '.') {
      if (p->child[word[i] - 'a'] == nullptr) return false;
      return search_helper(word, i + 1, p->child[word[i] - 'a']);
    }
    for (TrieNode*& q: p->child) {
      if (q == nullptr) continue;
      if (search_helper(word, i + 1, q)) return true;
    }
    return false;
  }
};

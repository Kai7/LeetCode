#include "utils/data_structure.hpp"


class Trie {
public:
  /* 86.67, 50.33 */
  class TrieNode {
  public:
    bool isWord;
    TrieNode *child[26];
    TrieNode(): isWord(false) {
    /*    (TrieNode*& n: next) */
      for (auto& n: child) { 
        n = nullptr;
      }
    }
  };

  TrieNode *root;
  Trie() {
    root = new TrieNode();
  }
  
  void insert(string word) {
    TrieNode *p = root;
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
    TrieNode *p = root;
    for (auto& c: word) {
      int idx = c - 'a';
      if (p->child[idx] == nullptr) {
        return false;
      }
      p = p->child[idx];
    }
    return p->isWord;
  }
  
  bool startsWith(string prefix) {
    TrieNode *p = root;
    for (auto& c: prefix) {
      int idx = c - 'a';
      if (p->child[idx] == nullptr) {
        return false;
      }
      p = p->child[idx];
    }
    return true;  
  }
};
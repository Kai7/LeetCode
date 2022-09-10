#include "utils/data_structure.hpp"

class Solution {
public:
  /* 79.04, 53.06 */
  void lowerAlphabet(string& s) {
    for (int i = 0; i < s.size(); ++i) {
    //   if (s[i] >= 0x61 && s[i] <= 0x5A) { // Wrong Answer
      if (s[i] >= 65 && s[i] <= 90) {
        s[i] += 32;
      }
    }
  }
  bool isAlphabet(char c) {
    if (c - 'a' >= 0 && c - 'a' < 26 ) return true;
    if (c - '0' >= 0 && c - '0' < 10 ) return true;
    return false;
  }
  bool isPalindrome(string s) {
    int left = 0, right = s.size() - 1;
    lowerAlphabet(s);
    while (!isAlphabet(s[left]) && left < right) ++left;
    while (!isAlphabet(s[right]) && left < right) --right;
    while (left < right) {
      if (s[left] != s[right]) return false;
      ++left;
      --right;
      while (!isAlphabet(s[left]) && left < right) ++left;
      while (!isAlphabet(s[right]) && left < right) --right;
    }

    return true;
  }
};
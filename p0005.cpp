#include "utils/data_structure.hpp"

class Solution {
public:
  /* 90.96, 99.94 */
  string longestPalindrome(string s) {
    int s_start = 0, s_end = 0;
    for (int i = 0; i < s.size() - 1; i++) {
      int left = i;
      int right = i;
      --left; ++right;
      while (left >= 0 && right < s.size()) {
        if (s[left] != s[right]) break;
        --left; ++right;
      }
      ++left; --right;
      if (right - left > s_end - s_start) {
        s_start = left;
        s_end = right;
      }
      left = i;
      right = i + 1;
      if (s[left] != s[right]) continue;
      --left; ++right;
      while (left >= 0 && right < s.size()) {
        if (s[left] != s[right]) break;
        --left; ++right;
      }
      ++left; --right;
      if (right - left > s_end - s_start) {
        s_start = left;
        s_end = right;
      }
    }
    return s.substr(s_start, s_end - s_start + 1);
  }
};
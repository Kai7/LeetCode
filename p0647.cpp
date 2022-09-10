#include "utils/data_structure.hpp"

class Solution {
public:
  /* 86.69, 83.97 */
  int countSubstrings(string s) {
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
      int left = i;
      int right = i;
      while (left >= 0 && right < s.size() && s[left] == s[right]) {
        ++ans;
        --left;
        ++right;
      }
      left = i;
      right = i + 1;
      while (left >= 0 && right < s.size() && s[left] == s[right]) {
        ++ans;
        --left;
        ++right;
      }
    }
    return ans;
  }
};
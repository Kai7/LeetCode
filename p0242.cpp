#include "utils/data_structure.hpp"
#include <algorithm>

#define METHOD 0

class Solution {
public:
#if METHOD == 0
  /* 90.60, 77.60 */
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    int m[26] = {0};
    for (int i = 0; i < s.size(); ++i) ++m[s[i] - 'a'];
    for (int i = 0; i < t.size(); ++i) {
        if (--m[t[i] - 'a'] < 0) return false;
    }
    return true;
  }
#elif METHOD == 2
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    vector<int> letter_count(26, 0);
    for (int i = 0; i < s.size(); ++i) {
      ++letter_count[s[i] - 'a'];
    }
    for (int i = 0; i < t.size(); ++i) {
      --letter_count[t[i] - 'a'];
      if (letter_count[t[i] - 'a'] < 0) return false;
    }
    return true;
  }
#elif METHOD == 1
  bool isAnagram(string s, string t) {
    std::sort(s.begin(), s.end());
    std::sort(t.begin(), t.end());
    return s == t;
  }
#else
#endif
};
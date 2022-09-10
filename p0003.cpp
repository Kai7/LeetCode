#include "utils/data_structure.hpp"

#define METHOD 0

#define MAX(a,b) (((a)>(b))?(a):(b))
class Solution {
public:
#if METHOD == 0
  /* 43.70, 74.62 */
  int lengthOfLongestSubstring(string s) {
    if (s.size() == 0) return 0;
    unordered_map<char, int> table;
    int ans = 1;
    int left = 0;
    table[s[0]] = 0;
    for (int right = 1; right < s.size(); right++) {
      if (table.find(s[right]) != table.end() && table[s[right]] >= left) {
        ans = MAX(ans, right - left);
        left = table[s[right]] + 1;
      }
      table[s[right]] = right;
    }
    ans = MAX(ans, s.size() - left);
    return ans;
  }
#elif METHOD == 1
  /* 43.70, 27.61 */
  int lengthOfLongestSubstring(string s) {
    if (s.size() == 0) return 0;
    unordered_map<char, int> table;
    int ans = 1;
    int left = 0;
    table[s[0]] = 0;
    for (int right = 1; right < s.size(); right++) {
      if (table.find(s[right]) != table.end()) {
        ans = MAX(ans, right - left);
        int match_idx = table[s[right]];
        for (int i = left; i <= match_idx; i++) {
          table.erase(s[i]);
        }
        left = match_idx + 1;
      }
      table[s[right]] = right;
    }
    ans = MAX(ans, s.size() - left);
    return ans;
  }
#else
#endif
};
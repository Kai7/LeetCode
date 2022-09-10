#include "utils/data_structure.hpp"

#define METHOD 0

class Solution {
public:
#if METHOD == 0
  /* 88.87, 71.90 */
  int firstUniqChar(string s) {
    vector<int> record(26, 0);
    for (const char& c: s) {
      ++record[c - 'a'];
    }
    for (int i = 0; i < s.size(); i++) {
      if (record[s[i] - 'a'] == 1) return i;
    }
    return -1;
  }

#elif METHOD == 1
  /* 61.80, 71.90 */
  int firstUniqChar(string s) {
    vector<int> record(26, 0);
    for (int i = 0; i < s.size(); ++i) {
      if (record[s[i] - 'a'] == -1) continue;
      if (record[s[i] - 'a'] > 0) {
        record[s[i] - 'a'] = -1;
        continue;
      } 
      record[s[i] - 'a'] = i + 1;
    }
    int ans = s.size() + 1;
    for (int i = 0; i < 26; ++i) {
      if (record[i] <= 0) continue;
      ans = std::min(ans, record[i] - 1);
    }
    return (ans == s.size() + 1) ? -1 : ans;
  }
#else
#endif
};
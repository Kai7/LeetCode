#include "utils/data_structure.hpp"

#define METHOD 0

class Solution {
public:
  /* 100.00, 77.10 */
  int len;
  int idx;
  bool isNumber(char c) {
    return c - '0' >= 0 && c - '0' <= 9;
  }
  string helper(string &s) {
    string ans;
    while (idx < len && s[idx] != ']') {
      if (!isNumber(s[idx])) {
        ans += s[idx];
        idx++;
      } else {
        int cnt = 0;
        while(isNumber(s[idx])) {
          cnt = cnt * 10 + (s[idx] - '0');
          idx++;
        }
        idx++;
        string tmp = helper(s);
        while (cnt > 0) {
          ans += tmp;
          cnt--;
        }
      }
    }
    idx++;
    return ans;
  }
  string decodeString(string s) {
    len = s.size();
    idx = 0;
    string ans = helper(s);
    return ans;
  }
};
#include "utils/data_structure.hpp"

#define METHOD 0

class Solution {
public:
#if METHOD == 0
  /* 100.00, 73.75 */
  int numDecodings(string s) {
    if (s[0] == '0') return 0;
    if (s.size() == 1) return 1;
    vector<int> dp(2, 0);
    dp[1] = 1;
    if (s[1] != '0') dp[0] += 1;
    if ((s[0] - '0') * 10 + (s[1] - '0') <= 26) dp[0] += 1;
    for (int i = 2; i < s.size(); ++i) {
      int tmp = 0;
      if (s[i] != '0') tmp += dp[0];
      if ((s[i - 1] != '0') && ((s[i-1] - '0') * 10 + (s[i] - '0') <= 26)) tmp += dp[1];
      if (tmp == 0) return 0;
      dp[1] = dp[0];
      dp[0] = tmp;
    }
    return dp[0];
  }
#elif METHOD == 1
  int numDecodings(string s) {
    if (s[0] == '0') return 0;
    if (s.size() == 1) return 1;
    /* case [i - 1]: pick 1 or 2 bits */
    vector<int> dp(3, 0);
    dp[1] = 1;  /* pick 1 bit  */
    dp[2] = 0;  /* pick 2 bits */
    for (int i = 1; i < s.size(); ++i) {
      if (s[i - 1] == '0') {
        dp[1] = (s[i] == '0') ? 0: dp[2];
        dp[2] = 0;
        continue;
      }
      if (s[i] == '0') {
        if (((s[i - 1] - '0') * 10 + (s[i] - '0')) > 26) {
          return 0;
        } else {
          dp[2] = dp[1];
          dp[1] = 0;
        }
        continue;
      }
      if (((s[i - 1] - '0') * 10 + (s[i] - '0')) > 26) {
        dp[1] = dp[1] + dp[2];
        dp[2] = 0;
      } else {
        int tmp = dp[2];
        dp[2] = dp[1];
        dp[1] = dp[1] + tmp;
      }
      if (dp[1] + dp[2] == 0) return 0;
    }
    return dp[1] + dp[2];
  }
#else
#endif
};
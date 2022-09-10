#include "utils/data_structure.hpp"

class Solution {
public:
  /* 82.10, 88.72 */
  bool wordBreak(string s, vector<string>& wordDict) {
    bool *dp = new bool[s.size() + 1];
    dp[0] = true;
    for (int i = 1; i <= s.size(); ++i) {
      dp[i] = false;
      for (const string & w: wordDict) {
        if (w.size() > i) {
          dp[i] = false;
          continue;
        }
        if (s.substr(i - w.size(), w.size()) == w) {
          if (dp[i - w.size()]) {
            dp[i] = true;
            break;
          }
        }
      }
    }
    bool ans = dp[s.size()];
    delete [] dp;
    return ans;
  }
};
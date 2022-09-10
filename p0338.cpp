#include "utils/data_structure.hpp"

#define METHOD 0

class Solution {
public:
#if METHOD == 0
  /* 38.34, 87.75 */
  vector<int> countBits(int n) {
    vector<int> dp(n + 1);
    dp[0] = 0;
    if (n == 0) return dp;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
      if (i & 1 > 0) {
        dp[i] = dp[i >> 1] + 1;
      } else {
        dp[i] = dp[i >> 1];
      }
    }
    return dp;
  }
#elif METHOD == 1
  /* 38.34, 33.56 */
  int bitsCount(int n, int counter) {
    if (n == 0) return counter;
    if (n & 1 > 0) ++counter;
    return bitsCount(n >> 1, counter);
  }
  vector<int> countBits(int n) {
    vector<int> ans;
    for (int i = 0; i <= n; ++i) {
      ans.push_back(bitsCount(i, 0));
    }
    return ans;
  }
#else
#endif
};
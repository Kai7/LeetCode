#include "utils/data_structure.hpp"

#define METHOD 0

#define MIN(a,b) (((a)<(b))?(a):(b))

class Solution {
public:

#if METHOD == 0
  int coinChange(vector<int>& coins, int amount) {
    int *dp = new int[amount + 1];
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i) {
      dp[i] = amount + 1;
      for (const int & cc: coins) {
        if (i < cc) continue;
        dp[i] = MIN(dp[i], dp[i - cc] + 1);
      }
    }
    int ans = (dp[amount] == amount + 1) ? -1 : dp[amount];
    delete [] dp;
    return ans;
  }

#elif METHOD == 1
  /* 99.71, 69.27 */
  int coinChange(vector<int>& coins, int amount) {
    int *dp = new int[amount + 1];
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i) {
      bool find_c = false;
      int min = -1;
      for (const int & cc: coins) {
        if (i - cc < 0) continue;
        if (dp[i - cc] >= 0) {
          if (!find_c) {
            find_c = true;
            min = dp[i - cc];
          } else {
            min = MIN(min, dp[i - cc]);
          }
        }
      }
      dp[i] = (find_c) ? min + 1 : -1;
      
    }
    int ans = dp[amount];
    delete [] dp;
    return ans;
  }
#else
#endif
};
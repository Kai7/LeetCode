#include "utils/data_structure.hpp"

class Solution {
public:
  /* 63.25, 66.70 */
  int combinationSum4(vector<int>& nums, int target) {
    // vector<int> dp(target + 1, 0); // runtime error
    vector<uint32_t> dp(target + 1, 0); // runtime error
    dp[0] = 1;
    for (int i = 1; i <= target; ++i) {
      for (const int & n: nums) {
        if (i < n) continue;
        dp[i] += dp[i - n];
      }
    }
    return dp[target];
  }
};
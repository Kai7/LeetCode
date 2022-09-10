#include "utils/data_structure.hpp"
// #include <algorithm>

class Solution {
public:
  /* 7.86, 37.93 */
  int jump(vector<int>& nums) {
    vector<int> dp(nums.size(), INT32_MAX);
    dp[0] = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (dp[i] == INT32_MAX) continue;
      for (int j = 1; j <= nums[i]; j++) {
        if ((i + j) >= nums.size()) break;
        dp[i + j] = std::min(dp[i + j], dp[i] + 1);
      }
    }
    return (dp.back() == INT32_MAX)? 0 : dp.back();
  }
};

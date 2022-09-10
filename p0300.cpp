#include "utils/data_structure.hpp"
#include <algorithm>

#define METHOD 0

#define MAX(a,b) (((a)>(b))?(a):(b))

class Solution {
public:
#if METHOD == 0
  /* 93.17, 87.63 */
  int lengthOfLIS(vector<int>& nums) {
    vector<int> result;
    for (int i = 0; i < nums.size(); ++i) {
      auto it = std::upper_bound(result.begin(), result.end(), nums[i]);
      if (it == result.end()) {
        result.push_back(nums[i]);
      } else {
        *it = nums[i];
      }
    }
    return result.size();
  }
#elif METHOD == 1
  /* 65.49, 24.23 */
  int lengthOfLIS(vector<int>& nums) {
    vector<int> dp(nums.size(), 0);
    dp[0] = 1;
    int ans = 1;
    for (int i = 1; i < nums.size(); ++i) {
      int max_length = 1;
      for (int j = i - 1; j >= 0; --j) {
        if (nums[i] > nums[j]) {
          max_length = MAX(max_length, dp[j] + 1);
        }
      }
      dp[i] = max_length;
      ans = MAX(ans, max_length);
    }
    return ans;
  }
#else
#endif
};
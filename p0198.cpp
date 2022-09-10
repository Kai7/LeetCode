#include "utils/data_structure.hpp"

#define METHOD 0

#define MAX(a,b) (((a)>(b))?(a):(b))
class Solution {
public:
#if METHOD == 0
  /* 100.00, 95.30 */
  int rob(vector<int>& nums) {
    int rob = 0, no_rob = 0;
    for (int i = 0; i < nums.size(); i++) {
      int preRob = rob;
      rob = nums[i] + no_rob;
      no_rob = MAX(preRob, no_rob);
    }
    return MAX(rob, no_rob);
  }
#elif METHOD == 3
  /* 100.00, 95.15 */
  int rob(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    if (nums.size() == 2) return MAX(nums[0], (nums[1]));
    nums[1] = MAX(nums[0], (nums[1]));
    for (int i = 2; i < nums.size(); ++i) {
      nums[i] = MAX(nums[i] + nums[i - 2], nums[i - 1]);
    }
    return MAX(nums[nums.size() - 2], nums[nums.size() - 1]);
  }
#elif METHOD == 2
  /* 35.98, 95.15 */
  int rob(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    if (nums.size() == 2) return MAX(nums[0], (nums[1]));
    nums[2] += nums[0];
    for (int i = 3; i < nums.size(); ++i) {
      nums[i] = MAX(nums[i] + nums[i - 2], nums[i] + nums[i - 3]);
    }
    return MAX(nums[nums.size() - 2], nums[nums.size() - 1]);
  }
#elif METHOD == 1
  /* 17.08, 24.80 */
  int rob(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    if (nums.size() == 2) return MAX(nums[0], (nums[1]));
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    dp[1] = nums[1];
    dp[2] = nums[0] + nums[2];
    for (int i = 3; i < nums.size(); ++i) {
      dp[i] = MAX(nums[i] + dp[i - 2], nums[i] + dp[i - 3]);
    }
    return MAX(dp[nums.size() - 2], dp[nums.size() - 1]);
  }
#else
#endif
};
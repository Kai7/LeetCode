#include "utils/data_structure.hpp"

#define METHOD 0

#define MAX(a,b) (((a)>(b))?(a):(b))
class Solution {
public:
#if METHOD == 0
  /* 100.00, 97.67 */
  int rob(vector<int>& nums, int left, int right) {
    if (left == right) return nums[left];
    int tmp_0 = nums[left];
    int tmp_1 = MAX(nums[left], nums[left + 1]);
    for (int i = left + 2; i <= right; ++i) {
      int tmp = tmp_1;
      tmp_1 = MAX(nums[i] + tmp_0, tmp_1);
      tmp_0 = tmp;
    }
    return tmp_1;
  }

  int rob(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    return (MAX(rob(nums, 0, nums.size() - 2), rob(nums, 1, nums.size() - 1)));
  }
#elif METHOD == 1
  /* 100.00, 19.35 */
  int rob(vector<int>& nums) {
      if (nums.size() == 1) return nums[0];
      if (nums.size() == 2) return MAX(nums[0], nums[1]);
      int ans;
      vector<int> dp(nums.size(), 0);
      /* pick nums[0]*/
      dp[0] = nums[0];
      dp[1] = MAX(nums[0], nums[1]);
      for (int i = 2; i < dp.size() - 1; ++i) {
        dp[i] = MAX(nums[i] + dp[i - 2], dp[i - 1]);
      }
      ans = dp[dp.size() - 2];
      /* do not pick nums[0]*/
      dp[1] = nums[1];
      dp[2] = MAX(nums[1], nums[2]);
      for (int i = 3; i < dp.size(); ++i) {
        dp[i] = MAX(nums[i] + dp[i - 2], dp[i - 1]);
      }
      ans = MAX(ans, dp[dp.size() - 1]);
      return ans; 
  }
#else
#endif
};
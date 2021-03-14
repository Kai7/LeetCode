#include <vector>
using std::vector;
#include <iostream>

#define MAX(a,b) (((a)>(b))?(a):(b))

class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int *dp = new int[nums.size()];
    int max_sum = nums[0];
    dp[0] = nums[0];

    for (int i = 1; i<nums.size(); i++){
      dp[i] = MAX(dp[i-1] + nums[i], nums[i]);
      if (dp[i] > max_sum) max_sum = dp[i];
    }
    delete [] dp;

    return max_sum;
  }


#if 0
  /* O(n^2) */
  int maxSubArray(vector<int>& nums) {
    int max_sum = nums[0];
    for (int i = 0; i < nums.size(); i++){
      int tmp_sum = nums[i];
      if (tmp_sum > max_sum) {
        max_sum = tmp_sum;
      }
      for (int j = i+1; j < nums.size(); j++){
        tmp_sum += nums[j];
        if (tmp_sum > max_sum) {
          max_sum = tmp_sum;
        }
      }
    }
    return max_sum;
  }
#endif
};
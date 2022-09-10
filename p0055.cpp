#include "utils/data_structure.hpp"

#define MAX(a,b) (((a)>(b))?(a):(b))
class Solution {
public:
  /* 65.24, 93.55 */
  bool canJump(vector<int>& nums) {
    if (nums.size() == 1) return true;
    if (nums[0] == 0) return false;
    int cur = 0;
    int farthest = nums[0];
    while (cur < farthest) {
      cur++;
      farthest = MAX(farthest, cur + nums[cur]);
      if (farthest >= nums.size() - 1) return true;
    }
    return cur == nums.size() - 1;
  }
};
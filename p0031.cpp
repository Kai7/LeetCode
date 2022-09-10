#include "utils/data_structure.hpp"
#include <algorithm>

class Solution {
public:
  /* 77.21, 36.41 */
  void nextPermutation(vector<int>& nums) {
    int i = nums.size() - 2;
    int j = nums.size() - 1;
    while (i >= 0 && nums[i] > nums[i + 1]) --i;
    if (i >= 0) {
      while (j > i && nums[j] <= nums[i]) --j;
      std::swap(nums[i], nums[j]);
    }
    std::reverse(nums.begin() + i + 1, nums.end());
    
#if 0
    int t = nums[p - 1];
    int l = p, r = nums.size() - 1;
    while (l <= r) {
      int m = (l + r) / 2;
      if (nums[m] < t) {
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    std::swap(nums[p - 1], nums[l]);
    std::reverse(nums.begin() + p, nums.end());
#endif
  }
};
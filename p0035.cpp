#include "utils/data_structure.hpp"

class Solution {
public:
  /* 32.49, 72.02 */
  int searchInsert(vector<int>& nums, int target) {
    // if (target < nums[0]) return 0; /* unnecessary */
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int m = (left + right) / 2;
      if (nums[m] >= target) {
        right = m - 1;
      } else {
        left = m + 1;
      }
    }
    return left;
  }
};
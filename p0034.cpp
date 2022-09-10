#include "utils/data_structure.hpp"

class Solution {
public:
  /* 43.16, 84.40 */
  vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.empty()) return vector<int>({-1, -1});
    int left = 0, right = nums.size() - 1;
    if (target > nums[right]) return vector<int>({-1, -1});
    while (left <= right) {
      int m = (left + right) / 2;
      if (nums[m] >= target) {
        right = m - 1;
      } else {
        left = m + 1;
      }
    }
    if (nums[left] != target) return vector<int>({-1, -1});
    vector<int> ans({left, -1});
    left = 0, right = nums.size() - 1;
    while (left <= right) {
      int m = (left + right) / 2;
      if (nums[m] > target) {
        right = m - 1;
      } else {
        left = m + 1;
      }
    }
    ans[1] = left - 1;

    return ans;
  }
};
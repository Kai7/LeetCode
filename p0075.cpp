#include "utils/data_structure.hpp"

class Solution {
public:
  /* 100.00, 23.79 */
  void quickSort(vector<int> &nums, int left, int right) {
    if (left >= right) return;
    int i = left;
    for (int j = left + 1; j <= right; j++) {
      if (nums[j] <= nums[left]) {
        std::swap(nums[++i], nums[j]);
      }
    }
    std::swap(nums[left], nums[i]);
    quickSort(nums, left, i - 1);
    quickSort(nums, i + 1, right);
  }

  void sortColors(vector<int>& nums) {
    quickSort(nums, 0, nums.size() - 1);
  }
};
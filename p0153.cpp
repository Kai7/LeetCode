#include "utils/data_structure.hpp"

class Solution {
public:
  int findPivot(vector<int>& nums, int l, int r) {
    if (l == r) return nums[l];
    int middle = (l + r) / 2;
    if (nums[middle] > nums[r]){
      return findPivot(nums, middle + 1, r);
    } else {
      return findPivot(nums, l, middle);
    }
  }
  int findMin(vector<int>& nums) {
    return findPivot(nums, 0, nums.size() - 1);
  }
};
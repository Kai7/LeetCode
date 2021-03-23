#include "utils/data_structure.hpp"
#include <iostream>

class Solution {
public:
  void nextPermutation(vector<int>& nums) {
    if (nums.size() == 1) return;
    size_t decrease_idx = nums.size() - 1;
    while (decrease_idx > 0) {
      if (nums[decrease_idx - 1] < nums[decrease_idx]){
        break;
      }
      decrease_idx--;
    }
    if (decrease_idx != 0) {
      size_t swap_idx = findMinGreaterIdx(nums, nums[decrease_idx-1], decrease_idx, nums.size() - 1);
      int tmp = nums[decrease_idx - 1];
      nums[decrease_idx - 1] = nums[swap_idx];
      while (swap_idx > nums.size() - 1) {
        if (tmp >= nums[swap_idx - 1]) break;
        nums[swap_idx] = nums[swap_idx - 1];
        swap_idx--;
      }
      nums[swap_idx] = tmp;
    }
    reverse(nums, decrease_idx, nums.size() - 1);
  }

private:
  size_t findMinGreaterIdx(vector<int> &nums, int target, size_t front, size_t rear) {
    for (size_t i = rear; i >= front; i--){
      if(nums[i] > target) return i;
    }
    return front;
  }

  void reverse(vector<int> &nums, size_t front, size_t rear){
    while (rear >= front) {
      int tmp = nums[front];
      nums[front] = nums[rear];
      nums[rear] = tmp;
      front++;
      rear--;
    }
  }
};
#include "utils/data_structure.hpp"
#include <iostream>

#define METHOD 0

class Solution {
public:
#if METHOD == 0

#elif METHOD == 1
  /* TODO: Review */
  /* Accepted: 100.00, 79.57 */
  int search(vector<int>& nums, int target) {
    // if (nums.size() == 1 && nums[0] != target) return -1;
    int front = -1, rear = -1;
    size_t pivot = findPivot(nums);
    if (target >= nums[0]) {
      front = 0;
      rear = pivot;
    } else {
      rear = nums.size() - 1;
      front = pivot + 1;
    }
    while (front <= rear){
      size_t mid = (front + rear) / 2;
      if (nums[mid] == target) return static_cast<int>(mid);
      if (target > nums[mid]) {
        front = mid + 1;
      } else {
        rear = mid - 1;
      }
    }
    return -1;
  }

private:
  size_t findPivot(vector<int> &nums) {
    if (nums.size() == 1) return 0;
    size_t front = 0, rear = nums.size() - 1;
    size_t pivot = rear / 2;
    while (pivot != nums.size() - 1 && nums[pivot] < nums[pivot + 1]){
      if (nums[pivot] >= nums[0]) {
        front = pivot + 1;
      } else {
        rear = pivot;
      }
      pivot = (front + rear) / 2;
    }
    return pivot;
  }
#else
#error ""
#endif
};
#include <vector>
using std::vector;
#include <iostream>

class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    int i = 0;
    do {
      if (target <= nums[i]) return i;
      i++;
    } while (i< nums.size());
    return i;
  }
};
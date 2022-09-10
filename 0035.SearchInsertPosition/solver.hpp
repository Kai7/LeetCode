#include <vector>
using std::vector;
#include <iostream>

#define METHOD 0

class Solution {
public:
#if METHOD == 0
  int searchInsert(vector<int>& nums, int target) {
    int l = 0, r = static_cast<int>(nums.size()) - 1;
    while (l <= r) {
      int m = (l + r) >> 1;
      if (nums[m] < target) {
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    return l;
  }

#elif METHOD == 1
  int searchInsert(vector<int>& nums, int target) {
    int i = 0;
    do {
      if (target <= nums[i]) return i;
      i++;
    } while (i< nums.size());
    return i;
  }

#elif
#error ""
#endif
};
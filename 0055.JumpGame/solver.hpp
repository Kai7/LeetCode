#include "utils/data_structure.hpp"
#include <iostream>


class Solution {
public:
  /* Accepted: 16.20, 73.42 */
  bool canJump(vector<int>& nums) {
    bool *table = new bool[nums.size()]();
    table[nums.size() - 1] = true;
    for (int i = static_cast<int>(nums.size() - 2); i >= 0; i--){
      for (int j = nums[i]; j >= 1; j--) {
        if (i + j > static_cast<int>(nums.size()-1)) continue;
        if (table[i+j]){
          table[i] = true;
          break;
        }
      }
    }
    bool ans = table[0];
    delete [] table;
    return ans;
  }

#if 0
  /* Accepted: 10.02, 35.81 */
  bool canJump(vector<int>& nums) {
    bool *table = new bool[nums.size()]();
    table[nums.size() - 1] = true;
    for (int i = static_cast<int>(nums.size() - 2); i >= 0; i--){
      for (int j = 1; j <= nums[i]; j--) {
        if (table[i+j]){
          table[i] = true;
          break;
        }
      }
    }
    bool ans = table[0];
    delete [] table;
    return ans;
  }
#endif

#if 0
  /* Time Limit Exceeded */
  bool canJump(vector<int>& nums) {
    return canJump(nums, 0);
  }

  bool canJump(vector<int>& nums, size_t start) {
    if (start == nums.size() - 1) return true;
    if (nums[start] == 0) return false;
    if (start + static_cast<size_t>(nums[start]) >= nums.size() - 1) return true;
    for (int i = 1; i <= nums[start]; i++){
      if (canJump(nums, start + static_cast<size_t>(i))) return true;
    }
    return false;
  }
#endif
};
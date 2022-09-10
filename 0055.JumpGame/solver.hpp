#include "utils/data_structure.hpp"
#include <iostream>
#include <cstring>

#define METHOD 0

class Solution {
public:
#if METHOD == 0
  bool canJump(vector<int>& nums) {
    int nums_size = static_cast<int>(nums.size());
    int far = nums[0];
    for (int i = 1; i < nums_size - 1; ++i) {
      if (i > far) return false;
      far = ( i + nums[i] > far) ? i + nums[i] : far;
      if (far >= nums_size - 1) return true;
    }
    return far >= nums_size - 1;
  }
#elif METHOD == 4
  bool canJump(vector<int>& nums) {
    bool *tb = new bool[nums.size()];
    std::memset(tb, false, sizeof(bool) * nums.size());
    tb[0] = true;
    int nums_size = static_cast<int>(nums.size());
    for (int i = 0; i < nums_size - 1; i++) {
      if (!tb[i]) {
        delete [] tb;
        return false;
      }
      if (i + nums[i] >= nums_size - 1) {
        delete [] tb;
        return true;
      }
      for (int j = 1; j <= nums[i]; j++) {
        tb[i+j] = true;
      }
    }
    bool ans = tb[nums.size() - 1];
    delete [] tb;
    return ans;
  }
#elif METHOD == 3
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

#elif METHOD == 2
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

#elif METHOD == 1
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
#else
#error ""
#endif
};
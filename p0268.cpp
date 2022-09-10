#include "utils/data_structure.hpp"

#define METHOD 0

class Solution {
public:

#if METHOD == 0
  /* 97.05, 18.76 */
  int missingNumber(vector<int>& nums) {
    int ans = 0;
    for (int i = 0; i < nums.size(); ++i) {
      ans ^= (i + 1) ^ nums[i];
    }
    return ans;
  }
#elif METHOD == 2
  /* 65.47, 63.93 */
  int missingNumber(vector<int>& nums) {
    int ans = 0;
    for (int i = 0; i <= nums.size(); ++i) {
      ans ^= i;
    }
    for (int i = 0; i < nums.size(); ++i) {
      ans ^= nums[i];
    }
    return ans;
  }
#elif METHOD == 1
  /* 33.25, 63.93 */
  int missingNumber(vector<int>& nums) {
    int ans = ((nums.size() + 1) * nums.size()) >> 1;
    for (const int & n: nums) {
      ans -= n;
    }
    return ans;
  }
#else
#endif
};
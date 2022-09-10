#include "utils/data_structure.hpp"

#define MAX(a,b) (((a)>(b))?(a):(b))
class Solution {
public:
  /* 63.28, 63.89 */
  int longestConsecutive(vector<int>& nums) {
    std::unordered_set<int> bag(nums.begin(), nums.end());
    int ans = 0;
    for (int n: nums) {
      if (!bag.count(n)) continue;
      bag.erase(n);
      int begin_value = n;
      int end_value = n;
      while(bag.count(begin_value - 1)) bag.erase(--begin_value);
      while(bag.count(end_value + 1)) bag.erase(++end_value); 
      ans = MAX(ans, end_value - begin_value + 1);
    }
    return ans;
  }
};
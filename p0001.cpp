#include "utils/data_structure.hpp"

#include <unordered_map>

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    std::vector<int> ans;
    std::unordered_map<int, int> bag;
    bag[nums[0]] = 0;
    for (int i = 1; i < nums.size(); ++i) {
      auto it = bag.find(target - nums[i]);
      if (it != bag.end()) {
        ans.push_back(it->second);
        ans.push_back(i);
        return ans;
      }
      bag[nums[i]] = i;
    }
    return ans;
  }
};
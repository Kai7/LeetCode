#include "utils/data_structure.hpp"

class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    std::set<int> bag;
    for (int i = 0; i < nums.size(); ++i) {
        if (bag.find(nums[i]) != bag.end()) {
            return true;
        }
        bag.insert(nums[i]);
    }
    return false;
  }
};
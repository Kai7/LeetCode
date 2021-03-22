#include "utils/utils.hpp" 
#include <iostream>

class Solution {
public:
  int singleNumber(vector<int>& nums) {
    unordered_map<int, int> counter;
    for (size_t i = 0; i < nums.size(); i++){
      if (counter.find(nums[i]) == counter.end()) counter[nums[i]] = 1;
      else counter[nums[i]] += 1;
    }
    for (auto &p: counter) {
      if (p.second == 1) return p.first;
    }
    std::cout << "Error!\n";
    return 0;
  }
};
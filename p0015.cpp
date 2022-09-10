#include "utils/data_structure.hpp"

#include <algorithm>

#define METHOD 0

class Solution {
public:
#if METHOD == 0
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < static_cast<int>(nums.size()) - 2; i++) {
      if (i > 0 && nums[i] == nums[i-1]) continue;
      int j = i + 1;
      int k = static_cast<int>(nums.size()) - 1;
      while (j < k) {
        int sum = nums[i] + nums[j] + nums[k];
        if (sum == 0) {
          ans.emplace_back(vector<int>({nums[i], nums[j], nums[k]}));
          ++j;
          while (j < k && nums[j] == nums[j-1]){
            ++j;
          }
        } else if (sum < 0){
          ++j;
          while (j < k && nums[j] == nums[j-1]){
            ++j;
          }
        } else {
          --k; 
          while (j < k && nums[k] == nums[k+1]){
            --k;
          }
        }
      }
    }
    return ans;
      
  }
  
#elif METHOD == 1
/* Wrong Answer (because the solution set must not contain duplicate triplets...) */
  void twoSum(vector<int>& nums, int target, int begin, vector<vector<int>>& result) {
    unordered_map<int, vector<int>> table;
    for (int i = begin; i < nums.size(); ++i) {
      auto it = table.find(target - nums[i]);
      if (it != table.end()) {
        for (const int& idx: it->second){
          result.emplace_back(vector<int>({nums[idx], nums[i]}));
        }
      }
      table[nums[i]].push_back(i);
    }
  }
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    for (int i = 0; i < nums.size() - 1; ++i) {
      vector<vector<int>> twoSum_result;
      twoSum(nums, -nums[i], i+1, twoSum_result);
      for (const auto & idxes: twoSum_result) {
        vector<int> v = idxes;
        v.insert(v.begin(), nums[i]);
        result.emplace_back(v);
      }
    }
    return result;
  }
#else
#endif
};
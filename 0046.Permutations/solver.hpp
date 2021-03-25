#include "utils/data_structure.hpp"
#include <iostream>
#include "stdio.h"

class Solution {
public:
  /* Accepted: 78.01, 71.67 */
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    if (nums.empty()) return ans;
    ans.push_back({nums[0]});
    for (size_t i = 1; i < nums.size(); i++){
      vector<vector<int>> original_ans = ans;
      for (size_t n = 0; n < ans.size(); n++){
        ans[n].insert(ans[n].begin(), nums[i]);
      }
      for (size_t j = 1; j <= i; j++){
        for (size_t n = 0; n < original_ans.size(); n++){
          vector<int> tmp = original_ans[n];
          tmp.insert(tmp.begin() + j, nums[i]);
          ans.push_back(tmp);
        }
      }
    }
    return ans;
  }
};
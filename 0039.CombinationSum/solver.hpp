#include "utils/data_structure.hpp"
#include <iostream>

#include <algorithm>

class Solution {
public:
  /* Accepted: 100.00, 51.63 */
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    std::sort(candidates.begin(), candidates.end());
    return combinationSum(candidates, target, 0);
  }
private:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target, size_t min_idx) {
    if (target == 0){
      vector<vector<int>> ans = {{}};
      return ans;
    }
    vector<vector<int>> ans;
    for (size_t i = min_idx; i < candidates.size(); i++) {
      if(target < candidates[i]) break;
      vector<vector<int>> sub_ans = combinationSum(candidates, target - candidates[i], i);
      for (size_t j = 0; j < sub_ans.size(); j++){
        sub_ans[j].push_back(candidates[i]);
        ans.push_back(sub_ans[j]);
      }
    }
    return ans;
  }
};
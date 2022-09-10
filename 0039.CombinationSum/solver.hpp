#include "utils/data_structure.hpp"
#include <iostream>
#include <functional>

#include <algorithm>

#define METHOD 0

class Solution {
public:
#if METHOD == 0
  void cSum(vector<int>& candidates, vector<int>& r, vector<vector<int>>& ans, int target, int i) {
    if (target == 0) {
      ans.push_back(r);
      return;
    }
    
    while (i != candidates.size() && target-candidates[i] >= 0) {
      r.push_back(candidates[i]);
      cSum(candidates, r, ans, target-candidates[i], i);
      i++;
      r.pop_back();
    }
  }
    
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    std::sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> r;
    cSum(candidates, r, ans, target, 0);
    return ans;
  }

#elif METHOD == 2
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    std::sort(candidates.begin(), candidates.end());
    int c_size = static_cast<int>(candidates.size());
    vector<int> combination;
    std::function<void(int, int)> cSum;
    cSum = [&cSum, &ans, &candidates, &c_size, &combination](int target, int min_idx){
      if(target == 0) {
        ans.push_back(combination);
        return;
      }
      for (int i = min_idx; i < c_size; ++i) {
        if (target - candidates[i] < 0) break;
        combination.push_back(candidates[i]);
        cSum(target - candidates[i], i);
        combination.pop_back();
      }
    };
    cSum(target, 0);

    return ans;
  }

#elif METHOD == 1
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
#else
#error ""
#endif
};
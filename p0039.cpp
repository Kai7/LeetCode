// #include "utils/data_structure.hpp"
#include <vector>
#include <functional>
using std::vector;

#define METHOD 0

class Solution {
public:
#if METHOD == 0
  /* 50.13, 75.04 */
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    std::sort(candidates.begin(), candidates.end());
    std::function<void(int, int)> dfs;
    vector<vector<int>> res;
    vector<int> current;
    dfs = [&dfs, &current, &candidates, &res](int idx, int t) {
      for (int i = idx; i < candidates.size(); i++) {
        if (candidates[i] > t) return;
        if (candidates[i] == t) {
          res.push_back(current);
          res.back().push_back(candidates[i]);
          continue;
        }
        current.push_back(candidates[i]);
        dfs(i, t - candidates[i]);
        current.pop_back();
      }
    };
    dfs(0, target);
    return res;
  }

#elif METHOD == 1
  /* TODO */
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<bool>> dp(candidates.size(), vector<bool>(target + 1, false));
    for (int i = 0; i < candidates.size(); i++) {
      dp[i][candidates[i]] = true;
      for (int j = candidates[i] + 1; j <= target; j++) {

      }
    }
      
  }
#else
#endif
};
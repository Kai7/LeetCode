#include "utils/data_structure.hpp"
#include <functional>

class Solution {
public:
  /* 31.19, 77.98 */
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    std::function<void(int)> dfs;
    dfs = [&dfs, &res, &nums](int idx) {
      if (idx == nums.size() - 1) {
        res.push_back(nums);
        return;
      }
      for (int i = idx; i < nums.size(); i++) {
        std::swap(nums[idx], nums[i]);
        dfs(idx + 1);
        std::swap(nums[idx], nums[i]);
      }
    };
    dfs(0);
    return res;
  }
};
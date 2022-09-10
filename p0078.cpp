#include "utils/data_structure.hpp"

class Solution {
public:
  /* 74.54, 87.57 */
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    ans.push_back(vector<int>({}));
    for (int i = 0; i < nums.size(); i++) {
      int n = ans.size();
      for (int j = 0; j < n; j++) {
        ans.push_back(ans[j]);
        ans.back().push_back(nums[i]);
      }
    }
    return ans;
  }
};
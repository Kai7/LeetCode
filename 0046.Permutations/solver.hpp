#include "utils/data_structure.hpp"
#include <iostream>
#include "stdio.h"

#include <algorithm>
#include <functional>

#define METHOD 0

class Solution {
public:
#if METHOD == 0
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    if (nums.empty()) return ans;
    int end_idx = static_cast<int>(nums.size()) - 1;
    std::function<void(int)> sub_permute;
    sub_permute = [&sub_permute, &nums, &ans, end_idx](int idx) {
      if (idx == end_idx) {
        ans.push_back(nums);
        return;
      }
      for (int i = idx; i <= end_idx; ++i) {
        std::swap(nums[idx], nums[i]);
        sub_permute(idx + 1);
        std::swap(nums[idx], nums[i]);
      }
    };
    sub_permute(0);

    return ans;
  }

#elif METHOD == 2
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    if (nums.empty()) return ans;
    int idx = 0;
    int end_idx = static_cast<int>(nums.size()) - 1;
    ans.push_back({nums[0]});
    ++idx;
    std::function<void()> sub_permute;
    sub_permute = [&sub_permute, &nums, &ans, &idx, end_idx]() {
      if (idx > end_idx) return;
      int curr_size = static_cast<int>(ans.size());
      for (int i = 0; i < curr_size; ++i) {
        for (int j = 1; j <= idx; ++j){
          vector<int> p = ans[i];
          p.insert(p.begin() + j, nums[idx]);
          ans.emplace_back(p);
        }
        ans[i].insert(ans[i].begin(), nums[idx]);
      }
      ++idx;
      sub_permute();
    };
    sub_permute();

    return ans;
  }

#elif METHOD == 1
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
#else
#error ""
#endif
};
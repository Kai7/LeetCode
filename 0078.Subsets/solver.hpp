#include "utils/data_structure.hpp"
#include <iostream>
#include <functional>

#include <iterator>
#define METHOD 0

class Solution {
public:
#if METHOD == 0
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    ans.push_back({});
    int rear_idx = static_cast<int>(nums.size()) - 1;
    std::function<void(int)> subsets_helper;
    subsets_helper = [&subsets_helper, &ans, &nums, &rear_idx](int idx) {
      vector<vector<int>> s_sets;
      for (vector<int> s : ans) {
        s.push_back(nums[idx]);
        s_sets.push_back(s);
        // s_sets.emplace_back(s);
      }
      for (vector<int> s : s_sets) {
        ans.push_back(s);
        // ans.emplace_back(s);
      }
      // ans.insert(ans.end(),
      //            std::make_move_iterator(s_sets.begin()),
      //            std::make_move_iterator(s_sets.end()));

      if (idx == rear_idx) return;
      subsets_helper(idx + 1);
    };
    subsets_helper(0);
    return ans;
  }
#elif METHOD == 2
  /* Accepted: 60.50, 98.88 */
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans = {{}};
    for (size_t i = 0; i < nums.size(); i++){
      vector<vector<int>> sub_ans = ans;
      for (size_t j = 0; j < sub_ans.size(); j++){
        sub_ans[j].push_back(nums[i]);
      }
      ans.insert(ans.end(), 
                 std::make_move_iterator(sub_ans.begin()), 
                 std::make_move_iterator(sub_ans.end()));
    }
    return ans;
  }

#elif METHOD == 1
  /* Accepted: 60.50, 79.53 */
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans = {{}};
    for (size_t i = 0; i < nums.size(); i++){
      vector<vector<int>> sub_ans = ans;
      for (size_t j = 0; j < sub_ans.size(); j++){
        sub_ans[j].push_back(nums[i]);
      }
      ans.insert(ans.end(), sub_ans.begin(), sub_ans.end());
    }
    return ans;
  }
#else
#error ""
#endif
};
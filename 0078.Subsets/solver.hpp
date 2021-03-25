#include "utils/data_structure.hpp"
#include <iostream>

#include <iterator>

class Solution {
public:
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

#if 0
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
#endif
};
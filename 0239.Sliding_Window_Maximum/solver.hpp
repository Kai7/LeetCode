#include "utils/data_structure.hpp"
#include <iostream>

class Solution {
public:
  /* Accepted: 62.06, 40.64 */
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    if (k > static_cast<int>(nums.size())) return ans;
    deque<int> w;
    for (int i = 0; i < k-1; i++){
      while(!w.empty() && nums[w.back()] <= nums[i]) {
        w.pop_back();
      }
      w.push_back(i);
    }
    for (int i = k-1; i < static_cast<int>(nums.size()); i++){
      if (!w.empty() && w.front() < i-k+1) w.pop_front();
      while(!w.empty() && nums[w.back()] <= nums[i]) {
        w.pop_back();
      }
      w.push_back(i);
      ans.push_back(nums[w.front()]);
    }
    return ans;
  }

#if 0
  /* Accepted: 50.33, 32.34 */
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    if (k > static_cast<int>(nums.size())) return ans;
    deque<pair<int, int>> w;
    for (int i = 0; i < k-1; i++){
      while(!w.empty() && w.back().first <= nums[i]) {
        w.pop_back();
      }
      w.push_back(pair<int, int>(nums[i], i));
    }
    for (int i = k-1; i < static_cast<int>(nums.size()); i++){
      if (!w.empty() && w.front().second < i-k+1) w.pop_front();
      while(!w.empty() && w.back().first <= nums[i]) {
        w.pop_back();
      }
      w.push_back(pair<int, int>(nums[i], i));
      ans.push_back(w.front().first);
    }
    return ans;
  }
#endif

#if 0
  /* Accepted: 11.16, 14.72 */
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    if (k > static_cast<int>(nums.size())) return ans;
    map<int, int> w;
    for (int i = 0; i < k-1; i++){
      if(w.find(nums[i]) != w.end()){
        w[nums[i]] += 1;
      } else {
        w[nums[i]] = 1;
      }
    };
    for (int i = k-1; i < static_cast<int>(nums.size()); i++) {
      if(w.find(nums[i]) != w.end()){
        w[nums[i]] += 1;
      } else {
        w[nums[i]] = 1;
      }
      ans.push_back(w.rbegin()->first);
      auto it = w.find(nums[i-k+1]);
      it -> second -= 1;
      if (it->second == 0) {
        w.erase(it);
      }
    }

    return ans;
  }
#endif
};
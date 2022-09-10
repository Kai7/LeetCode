#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
using std::vector;
using std::map;
using std::unordered_map;
using std::sort;
#include <iostream>

#define METHOD 0

class Solution {
public:
#if METHOD == 0
  vector<vector<int>> threeSum(vector<int>& nums) {
    /* 64.52, 87.42 */
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < static_cast<int>(nums.size()) - 2; i++) {
      if (i > 0 && nums[i] == nums[i-1]) continue;
      int j = i + 1;
      int k = static_cast<int>(nums.size()) - 1;
      while (j < k) {
        int sum = nums[i] + nums[j] + nums[k];
        if (sum == 0) {
          // ans.push_back(vector<int>({nums[i], nums[j], nums[k]}));  // faster than 33.64%
          ans.emplace_back(vector<int>({nums[i], nums[j], nums[k]}));
          j += 1;
          while (j < k && nums[j] == nums[j-1]){
            j += 1;
          }
        } else if (sum < 0){
          j += 1;
        } else {
          k -= 1;
        }
      }
    }
    return ans;
  }

#elif METHOD == 1
  /* 19.04, 50.90 */
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    if (nums.size() < 3) return ans;

    /* Note: Can't use unordered_map */
    map<int, int> map_num2count;
    for (size_t i = 0; i < nums.size(); i++){
      map<int, int>::iterator it = map_num2count.find(nums[i]);
      if (it != map_num2count.end()){
        it->second += 1;
      } else {
        map_num2count[nums[i]] = 1;
      }
    }

    map<int, int>::iterator idx_1 = map_num2count.begin();
    while(idx_1 != map_num2count.end()){
      idx_1->second -= 1;
      map<int, int>::iterator idx_2 = idx_1;
      while(idx_2 != map_num2count.end()){
        if (idx_2->second <= 0){
          idx_2++;
          continue;
        }
        idx_2->second -= 1;
        int target = 0 - idx_1->first - idx_2->first;
        map<int, int>::iterator idx_3 = map_num2count.find(target);
        if (idx_3 != map_num2count.end() && idx_3->second > 0 && idx_3->first >= idx_2->first){
          ans.push_back(vector<int>({idx_1->first, idx_2->first, idx_3->first}));
        }
        idx_2->second += 1;
        idx_2++;
      }
      idx_1->second += 1;
      idx_1++;
    }

    return ans;
  }
#else
#error "error"
#endif
};
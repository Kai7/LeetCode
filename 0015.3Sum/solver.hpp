#include <vector>
#include <map>
using std::vector;
using std::map;
#include <iostream>

class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    if (nums.size() < 3) return ans;

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
};
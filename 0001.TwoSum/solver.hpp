#include <vector>
#include <map>
using std::vector;
using std::map;
#include <iostream>

class Solution{
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> result;
    map<int, int> hash_table;
    for (size_t i=0; i<nums.size(); i++){
      hash_table[nums[i]] = i;
    }
    for (size_t i = 0; i<nums.size(); i++){
      map<int, int>::iterator it = hash_table.find(target - nums[i]);
      if (it != hash_table.end() && i != it->second){
        result.push_back(i);
        result.push_back(it->second);
        return result;
      }
    }
    return result;
  }
/*
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> result;
        for (size_t i = 0; i<nums.size(); i++){
            for (size_t j = i+1; j<nums.size(); j++){
                if(nums[i]+nums[j] == target){
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
    }
*/
};
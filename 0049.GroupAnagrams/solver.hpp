#include "utils/data_structure.hpp"
#include <iostream>
#include "stdio.h"

#include <algorithm>

class Solution {
public:
  /* Accepted: 67.68, 84.14 */
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<string, vector<size_t>> map_anagrams2idxes;
    for (size_t i = 0; i < strs.size(); i++){
      string word = strs[i];
      std::sort(word.begin(), word.end());
      if (map_anagrams2idxes.find(word) == map_anagrams2idxes.end()){
        map_anagrams2idxes[word] = {};
      }
      map_anagrams2idxes[word].push_back(i);
    }
    vector<vector<string>> ans;
    for (map<string, vector<size_t>>::iterator it = map_anagrams2idxes.begin();
         it != map_anagrams2idxes.end(); it++){
      ans.push_back({});
      for (size_t &idx: it->second){
        ans.back().push_back(strs[idx]);
      }
    }
    return ans;
  }
};
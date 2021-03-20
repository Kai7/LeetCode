#include <string>
#include <vector>
using std::string;
using std::vector;
#include <iostream>

class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 0) return "";
    if (strs.size() == 1) return strs[0];
    size_t len = 0;
    bool same = true;
    while (same) {
      if (len >= strs[0].size()) break;
      char c = strs[0][len];
      for (size_t i = 1; i < strs.size(); i++){
        if (len >= strs[i].size() || strs[i][len] != c){
          same = false;
          break;
        }
      }
      if (same) len += 1;
    }
    return strs[0].substr(0, len);
  }
};
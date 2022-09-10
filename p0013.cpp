#include "utils/data_structure.hpp"

class Solution {
public:
  /* 21.15, 43.03 */
  int romanToInt(string s) {
    int ans = 0;
    unordered_map<char, int> dict = { 
      { 'I' , 1 }, { 'V' , 5 }, 
      { 'X' , 10 }, { 'L' , 50 }, 
      { 'C' , 100 }, { 'D' , 500 },
      { 'M' , 1000 } };
    for (int i = 0; i <= static_cast<int>(s.length()) - 2; i++) {
      if (dict[s[i]] >= dict[s[i+1]]) {
        ans += dict[s[i]];
      } else {
        ans -= dict[s[i]];
      }
    }
    ans += dict[s.back()];
    return ans;
  }
};
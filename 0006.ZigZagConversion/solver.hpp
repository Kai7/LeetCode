#include <string>
using std::string;
#include <iostream>

class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows == 1) return s;
    string ans = "";
    size_t height = static_cast<size_t>(numRows);
    for (size_t i = 0; i < height; i++){
      size_t idx = i;
      if (i == 0 || i == height - 1) {
        while (idx < s.size()){
          ans += s[idx];
          idx += (height - 1) * 2;
        }
      } else {
        while (idx < s.size()){
          ans += s[idx];
          idx += (height - 1 - i) * 2;
          if (idx >= s.size()) break;
          ans += s[idx];
          idx += i * 2;
        }
      }
    }
    return ans;
  }
};
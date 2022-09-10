#include <string>
#include <map>
#include <unordered_map>
using std::string;
using std::map;
using std::unordered_map;
#include <iostream>

#define METHOD 2

class Solution {
public:
#if METHOD == 2
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

#elif METHOD == 1
  int romanToInt(string s) {
    int ans = 0;
    // map<char, int> dict = {
    unordered_map<char, int> dict = { 
      { 'I' , 1 }, { 'V' , 5 }, 
      { 'X' , 10 }, { 'L' , 50 }, 
      { 'C' , 100 }, { 'D' , 500 },
      { 'M' , 1000 } };

    ans += dict[s.back()];
    int next = ans;
    for (int i = s.length()-2 ; i >= 0 ; i--){
      int current = dict[s[i]];
      if (current >= next){
        ans += current;
      }else {
        ans -= current;
      }
      next = current;
    }

    return ans;
  }
  #else
  #error "error"
  #endif
};
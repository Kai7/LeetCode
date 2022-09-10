#include "utils/data_structure.hpp"

class Solution {
public:
  /* 76.53, 43.97 */
  vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    vector<string> ans;
    for (const string & s: words) {
      set<char> bag;
      unordered_map<char, char> charMap;
      bool matched = true;
      for (int i = 0; i < s.size(); ++i) {
        if (charMap.find(pattern[i])!= charMap.end()) {
          if (charMap[pattern[i]] != s[i]) {
              matched = false;
              break;
          }
        } else {
          if (bag.find(s[i]) != bag.end()) {
              matched = false;
              break;
          }
          charMap[pattern[i]] = s[i];
          bag.insert(s[i]);
        }
      }
      if (matched) {
        ans.push_back(s);
      }
    }
    return ans;
  }
};
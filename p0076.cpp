#include "utils/data_structure.hpp"

class Solution {
public:
  /* 40.80, 68.31 */
  string minWindow(string s, string t) {
    unordered_map<char, int> req;
    for (char & c: t) {
      if (req.find(c) != req.end()) {
        req[c] += 1;
      } else {
        req[c] = 1;
      }
    }
    int min_value = INT32_MAX;
    int min_start = -1, min_end = -1;
    int start = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (req.find(s[i]) == req.end()) continue;
      req[s[i]]--;
      bool match = true;
      auto it = req.begin();
      while (it != req.end()) {
        if (it->second > 0) {
          match = false;
          break;
        }
        ++it;
      }
      if (!match) continue;
      while (start < i) {
        if (req.find(s[start]) == req.end()) {
          ++start;
        } else {
          if (req[s[start]] < 0) {
            ++req[s[start]];
            ++start;
          } else {
            break;
          }
        }
      }
      if (i - start + 1 < min_value) {
        min_start = start;
        min_end = i;
        min_value = i - start + 1;
      }
      ++req[s[start]];
      ++start;
    }
    if (min_start < 0) return "";
    return s.substr(min_start, min_value);
  }
};
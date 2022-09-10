#include "utils/data_structure.hpp"
#include <algorithm>

#define METHOD 0

class Solution {
public:
#if METHOD == 0
  /* 52.33, 95.12 */
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    unordered_map<string, int> table;
    for (int i = 0; i < strs.size(); ++i) {
      string tmp = strs[i];
      std::sort(tmp.begin(), tmp.end());
      if (!table.count(tmp)) {
        table[tmp] = ans.size();
        ans.push_back(vector<string>({}));
      }
      ans[table[tmp]].push_back(strs[i]);
    }
    return ans;
  }

#elif METHOD == 1
  /* Time Limit Exceeded */
  int searchGroupIndex(vector<vector<int>>& key, vector<int>& key_size, string& s) {
    for (int i = 0; i < key.size(); i++) {
      if (key_size[i] != s.size()) continue;
      vector<int> tmp = key[i];
      bool match = true;
      for (int j = 0; j < s.size(); j++) {
        if (--tmp[s[j] - 'a'] < 0) {
          match = false;
          break;
        }
      }
      if (match) return i;
    }

    return -1;
  }
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    vector<vector<int>> key;
    vector<int> key_size;
    for (int i = 0; i < strs.size(); i++) {
      int idx = searchGroupIndex(key, key_size, strs[i]);
      if (idx == -1) {
        vector<int> counter(26, 0);
        for (int j = 0; j < strs[i].size(); j++) {
          ++counter[strs[i][j] - 'a'];
        }
        key.push_back(counter);
        key_size.push_back(strs[i].size());
        ans.push_back(vector<string>({strs[i]}));
      } else {
        ans[idx].push_back(strs[i]);
      }
    } 
    return ans;
  }
#else
#endif
};
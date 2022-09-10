#include "utils/data_structure.hpp"
// #include <algorithm>

#define METHOD 0

class Solution {
public:
#if METHOD == 0
  /* 75.28, 40.67 */
  void charCount(const string & w, vector<int> & counter) {
    for (const char & c: w) {
      ++counter[c - 'a'];
    }
  }
  vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
    vector<string> ans;
    vector<int> charNeeded(26, 0);
    for (const string & w2: words2) {
      vector<int> sub_needed(26, 0);
      charCount(w2, sub_needed);
      for (int i = 0; i < 26; ++i) {
        charNeeded[i] = std::max(charNeeded[i], sub_needed[i]);
      }
    }
    for (const string & w1: words1) {
      vector<int> c_counter(26, 0);
      charCount(w1, c_counter);
      bool is_subset = true;
      for (int i = 0; i < 26; ++i) {
        if (c_counter[i] < charNeeded[i]) {
          is_subset = false;
          break;
        }
      }
      if (is_subset) {
        ans.push_back(w1);
      }
    }
    return ans;
  }
#elif METHOD == 0
  /* Time Limit Exceeded */
  vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
    vector<string> ans;
    vector<unordered_map<char, int>> charCounter;
    for (const string & w: words2) {
      unordered_map<char, int> counter;
      for (const char & c: w) {
        counter[c] += 1;
      }
      charCounter.emplace_back(counter);
    }
    for (const string & w: words1) {
      unordered_map<char, int> counter_1;
      for (const char & c: w) {
        counter_1[c] += 1;
      }
      bool is_subset = true;
      for (int i = 0; i < words2.size(); ++i) {
        unordered_map<char, int> &counter_2 = charCounter[i];
        auto it = counter_2.begin();
        while (it != counter_2.end()) {
          if (counter_1[it->first] < it->second) {
            is_subset = false;
            break;
          }
          ++it;
        }
        if (!is_subset) {
          break;
        }
      }
      if (is_subset) {
        ans.push_back(w);
      }
    }
    return ans;
  }
#else
#endif
};
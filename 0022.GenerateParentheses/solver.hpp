#include "utils/data_structure.hpp"
#include <iostream>
#include <functional>

#define METHOD 0

class Solution {
public:
#if METHOD == 0

  /* 52.45, 87.08 */
  vector<string> generateParenthesis(int n) {
    string s;
    vector<string> ans;
    int l = 0, r = 0;
    std::function<void()> backtracking;
    backtracking = [&backtracking, &ans, &s, &l, &r, n]() {
      if (r == n) {
        ans.push_back(s);
        return;
      }
      if (l < n) {
        ++l;
        s += '(';
        backtracking();
        s.pop_back();
        --l;
      }
      if (l > r) {
        ++r;
        s += ')';
        backtracking();
        s.pop_back();
        --r;
      }
    };
    backtracking();
    
    return ans;
  }

#elif METHOD == 1
  vector<string> generateParenthesis(int n) {
    vector<string> ans = genSubParenthesis(0, 0, n);
    return ans;
  }

  vector<string> genSubParenthesis(int idx_l, int idx_r, int n) {
    if (idx_l == n) {
      string r = "";
      for (int i = idx_r; i < n; i++) r += ")";
      vector<string> ans = {r};
      return ans;
    }
    vector<string> ans_l = genSubParenthesis(idx_l + 1, idx_r, n);
    for (size_t i = 0; i < ans_l.size(); i++) ans_l[i] = "(" + ans_l[i];
    if (idx_l == idx_r) {
      return ans_l;
    }
    vector<string> ans_r = genSubParenthesis(idx_l, idx_r + 1, n);
    for (size_t i = 0; i < ans_r.size(); i++) ans_r[i] = ")" + ans_r[i];
    ans_l.insert(ans_l.end(), ans_r.begin(), ans_r.end());
    return ans_l;
  }

#else
#error ""
#endif
};
#include "utils/data_structure.hpp"
#include <iostream>

class Solution {
public:
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
};
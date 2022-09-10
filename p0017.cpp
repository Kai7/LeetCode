#include "utils/data_structure.hpp"
#include <functional>

class Solution {
public:
  /* 31.26, 53.95 */
  const static vector<string> letters;
  vector<string> letterCombinations(string digits) {
    if (digits.size() == 0) return {""};
    vector<string> res;
    string s;
    std::function<void(int)> dfs;
    dfs = [&dfs, &res, &digits, &s] (int idx) {
      if (idx == digits.size()) {
        res.push_back(s);
        return;
      }
      for (const char & c: letters[digits[idx] - '0']) {
        s.push_back(c);
        dfs(idx + 1);
        s.pop_back();
      }
    };
    dfs(0);
    return res;
  }
};

const vector<string> Solution::letters = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
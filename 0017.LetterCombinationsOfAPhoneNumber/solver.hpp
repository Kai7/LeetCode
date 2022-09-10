#include <string>
#include <vector>
using std::string;
using std::vector;
#include <iostream>

class Solution {
public:
  /* 100.00, 34.70 */
  vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if (digits.size() == 0) return ans;
    vector<string> letters = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string target = letters[digits[0] - '0'];
    for (size_t i = 0; i < target.size(); i++) {
      ans.push_back(target.substr(i,1));
    }
    for (size_t n = 1; n < digits.size(); n++){
      target = letters[digits[n] - '0'];
      vector<string> tmp_ans = ans;
      for (size_t i = 0; i < ans.size(); i++){
        ans[i] += target.substr(0,1);
      }
      for (size_t j = 1; j < target.size(); j++){
        for (size_t i = 0; i < tmp_ans.size(); i++) {
          ans.push_back(tmp_ans[i] + target.substr(j,1));
        }
      }
    }
    return ans;
  }
};
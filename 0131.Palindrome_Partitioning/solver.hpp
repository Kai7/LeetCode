#include "utils/data_structure.hpp"
#include <iostream>

class Solution {
public:
  /* Accepted: 91.07, 75.03 */
  vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> part;
    genPartition(s, 0, s.size() - 1, part, ans);
    return ans;
  }
  void genPartition(string &s, int front, int rear,
                    vector<string> &part,
                    vector<vector<string>> &ans) {
    if (front > rear) {
      ans.push_back(part);
      return;
    } 
    if (front == rear) {
      part.push_back(s.substr(front, 1));
      ans.push_back(part);
      part.pop_back();
      return;
    }
    for (int i = front; i <= rear; i++){
      if (isPalindrome(s, front, i)) {
        part.push_back(s.substr(front, i - front + 1));
        genPartition(s, i + 1, rear, part, ans);
        part.pop_back();
      }
    }
  }

#if 0
  /* Accepted: 7.96, 34.97 */
  vector<vector<string>> partition(string s) {
    vector<vector<string>> ans = partition(s, 0, s.size() - 1);
    return ans;
  }
  vector<vector<string>> partition(string s, int front, int rear) {
    if (front > rear) return {{}};
    if (front == rear) return {{s.substr(front, 1)}};
    vector<vector<string>> ans;
    for (int i = front; i <= rear; i++){
      if (isPalindrome(s, front, i)) {
        string palindrome = s.substr(front, i - front + 1);
        vector<vector<string>> sub_ans = partition(s, i + 1, rear);
        for (vector<string> &v: sub_ans){
          v.insert(v.begin(), palindrome);
        }
        ans.insert(ans.begin(), 
                   std::make_move_iterator(sub_ans.begin()), 
                   std::make_move_iterator(sub_ans.end()));
      }
    }
    return ans;
  }
#endif

private:
  bool isPalindrome(string &s, int front, int rear){
    while(front < rear){
      if (s[front++] != s[rear--]) return false;
    }
    return true;
  }
};
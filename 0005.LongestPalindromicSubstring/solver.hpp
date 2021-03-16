#include <string>
using std::string;
#include <iostream>

bool isPalindrome(string s){
  for (size_t i = 0; i <= (s.size() - 1) / 2; i++){
    if (s[i] != s[s.size()-1-i]){
      return false;
    }
  }
  return true;
}

int maxLengthPalindromeAroundCenter(string s, size_t left, size_t right){
  int L = static_cast<int>(left);
  int R = static_cast<int>(right);
  while (L >= 0 && R < s.size()){
    if (s[L] != s[R]) break;
    L--;
    R++;
  }
  return R - L - 1;
}

class Solution {
public:
  /* O(n^2) */
  string longestPalindrome(string s) {
    int max_len = 1;
    size_t front = 0, rear = 0;
    for (size_t i = 1; i < s.size(); i++) {
      int len = maxLengthPalindromeAroundCenter(s, i-1, i);
      if (len > max_len){
        max_len = len;
        front = i - len / 2;
        rear = i + len / 2 - 1;
      }
      len = maxLengthPalindromeAroundCenter(s, i, i);
      if (len > max_len){
        max_len = len;
        front = i - len / 2;
        rear = i + len / 2;
      }
    }
    return s.substr(front, static_cast<size_t>(max_len));
  }

# if 0
  /* O(n^3), Time Limit Exceeded */
  string longestPalindrome(string s) {
    string ans = "";
    for (size_t len = 1; len <= s.size(); len++){
      for (size_t i = 0; i <= s.size() - len; i++){
        string sub_s = s.substr(i, len);
        if (isPalindrome(sub_s) && sub_s.size() > ans.size()){
          ans = sub_s;
        }
      }
    }
    return ans; 
  }
#endif
};
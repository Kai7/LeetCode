#include "utils/data_structure.hpp"
#include <iostream>
#include "stdio.h"

#define MAX(a,b) (((a)>(b))?(a):(b))

#define METHOD 0

class Solution {
public:
#if METHOD == 0
  /* OK */
  string multiply(string num1, string num2) {
    int len1 = static_cast<int>(num1.length());
    int len2 = static_cast<int>(num2.length());
    int ans_length = len1 + len2;
    string ans(ans_length, '0');
    for (int i1 = len1 - 1; i1 >= 0; --i1) {
      for (int i2 = len2 - 1; i2 >= 0 ; --i2) {
        int idx = i1 + i2 + 1;
        int c = (ans[idx] - '0') + (num1[i1] - '0') * (num2[i2] - '0');
        ans[idx] = '0' + ( c % 10 );
        ans[idx-1] += ( c / 10 );
      }
    }
    for (int i = 0; i < ans_length; ++i) {
      if (ans[i] != '0') return ans.substr(i);
    }
    return ans.substr(ans_length - 1);
  }

#elif METHOD == 1
  /* Accepted: 9.84, 5.04 */
  string multiply(string num1, string num2) {
    string ans = "0";
    for (size_t i = 0; i < num2.size(); i++){
      int carry = 0;
      string tmp_ans = "";
      int n2 = num2[num2.size() - 1 - i] - '0';
      for (size_t j = 0; j < num1.size(); j++){
        int n1 = num1[num1.size() - 1 -j] - '0';
        int m = n1 * n2 + carry;
        carry = m / 10;
        m %= 10;
        tmp_ans = "0" + tmp_ans;
        tmp_ans[0] += m;
      }
      if (carry != 0){
        tmp_ans = "0" + tmp_ans;
        tmp_ans[0] += carry;
      }
      for(size_t z = 0; z < i ; z++){
        tmp_ans += "0";
      }
      tmp_ans = (tmp_ans[0] == '0')? "0" : tmp_ans;
      ans = add(ans, tmp_ans);
    }
    return ans;
  }

  string add(string num1, string num2) {
    if (num1.empty() || num2.empty()) {
      return "";
    }
    printf("add (%s,%s)\n", num1.c_str(), num2.c_str());
    bool carry = false; 
    string ans = "";
    for (size_t i = 0; i < MAX(num1.size(), num2.size()); i++) {
      int n1 = (i >= num1.size())? 0: num1[num1.size() - 1 -i] - '0';
      int n2 = (i >= num2.size())? 0: num2[num2.size() - 1 -i] - '0';
      // printf("  (%d,%d)\n", n1, n2);
      int a = n1 + n2 + ((carry)? 1: 0);
      if (a >= 10){
        carry = true;
        a -= 10;
      } else {
        carry = false;
      }
      ans = "0" + ans;
      ans[0] += a;
    }
    if (carry) return "1" + ans;
    if (ans[0] == '0') return "0";
    return ans;
  }

#else
#error ""
#endif
};
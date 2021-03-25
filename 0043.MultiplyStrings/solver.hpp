#include "utils/data_structure.hpp"
#include <iostream>
#include "stdio.h"

#define MAX(a,b) (((a)>(b))?(a):(b))

class Solution {
public:
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
};
#include <iostream>

class Solution {
public:
  int reverse(int x) {
    if (x == 0x80000000){
      return 0;
    }
    int max_value = 0x7fffffff;
    int max_r = max_value % 10;
    int ans = 0;
    int q = (x > 0) ? x : -1 * x;
    while(q > 0){
      int r = q % 10;
      if (max_value /10 < ans  || 
          (max_value / 10 == ans && r > max_r)){
        return 0;
      }
      ans = ans * 10 + r;
      q = q / 10;
    }
    ans = (x > 0) ? ans : -1 * ans;
    return ans;
  }
};
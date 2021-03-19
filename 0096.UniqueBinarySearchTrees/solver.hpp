#include <iostream>

class Solution {
public:
  int numTrees(int n) {
    int *ans_table = new int[n+1];
    ans_table[0] = 1;
    ans_table[1] = 1;
    for (int i = 2; i <= n; i++){
      ans_table[i] = 0;
      for (int j = 0; j < i; j++){
        ans_table[i] += ans_table[j] * ans_table[i-1-j];
      }
    }
    int ans = ans_table[n];
    delete [] ans_table;
    return ans;
  }

#if 0
  /* Time Limit Exceeded */
  int numTrees(int n) {
    if (n == 0 || n == 1) return 1;
    int ans = 0;
    for (int i = 1; i <= n; i++){
      ans += numTrees(i - 1) * numTrees(n - i);
    }
    return ans;
  }
#endif
};
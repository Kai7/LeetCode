#include "utils/data_structure.hpp"
#include <cstring>

#define METHOD 0

#define MIN(a,b) (((a)<(b))?(a):(b))

class Solution {
public:
#if METHOD == 0
  /* 100.00, 98.47 */
  int uniquePaths(int m, int n) {
    int min = MIN(m - 1,n - 1), sum = m + n - 2;
    long numerator = 1, denominator = 1;
    for (int i = 1; i <= min; i++) {
      numerator *= i;
      denominator *= sum - i + 1;
      if (denominator > INT32_MAX){
        while(denominator % 2 == 0 && numerator % 2 == 0){
          denominator /= 2;
          numerator /= 2;
        }
        while(denominator % 3 == 0 && numerator % 3 == 0){
          denominator /= 3;
          numerator /= 3;
        }
      }
    }
    return static_cast<int>(denominator / numerator);
  }
#elif METHOD == 1
  /* 100.00, 54.99 */
  int uniquePaths(int m, int n) {
    int **dp = new int*[m];
    for (int i = 0; i < m; ++i) {
      dp[i] = new int[n];
      dp[i][0] = 1;
    }
    for (int j = 0; j < n; ++j) {
      dp[0][j] = 1;
    }
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
      }
    }
    int ans = dp[m - 1][n - 1];
    for (int i = 0; i < m; ++i) {
      delete [] dp[i];
    }
    delete [] dp;
    return ans;
  }
#else
#endif
};
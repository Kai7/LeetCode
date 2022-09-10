#include "utils/data_structure.hpp"

#define MAX(a,b) (((a)>(b))?(a):(b))

class Solution {
public:
  /* 85.30, 56.73 */
  int longestCommonSubsequence(string text1, string text2) {
    int **dp = new int*[text1.size()];
    for (int i = 0; i < text1.size(); ++i) {
      dp[i] = new int[text2.size()];
    }
    for (int i = 0; i < text1.size(); ++i) {
      if (text1[i] == text2[0]) {
        dp[i][0] = 1;
        for (int ii = i + 1; ii < text1.size(); ++ii) {
          dp[ii][0] = 1;
        }
        break;
      }
      dp[i][0] = 0;
    }
    for (int j = 0; j < text2.size(); ++j) {
      if (text1[0] == text2[j]) {
        dp[0][j] = 1;
        for (int jj = j + 1; jj < text2.size(); ++jj) {
          dp[0][jj] = 1;
        }
        break;
      }
      dp[0][j] = 0;
    }
    for (int i = 1; i < text1.size(); ++i) {
      for (int j = 1; j < text2.size(); ++j) {
        if (text1[i] == text2[j]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = MAX(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
    int ans = dp[text1.size() - 1][text2.size() - 1];
    for (int i = 0; i < text1.size(); ++i) {
      delete [] dp[i];
    }
    delete [] dp;
    return ans;
  }
};
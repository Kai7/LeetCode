
class Solution {
public:
  /* 100.00, 30.91 */
  int climbStairs(int n) {
    if (n == 1 || n == 2) return n;
    int *dp = new int[n+1];
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; ++i) {
      dp[i] = dp[i - 2] + dp[i - 1];
    }
    int ans = dp[n];
    delete [] dp;
    return ans;
  }
};
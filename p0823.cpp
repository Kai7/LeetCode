#include "utils/data_structure.hpp"
#include <algorithm>

#define MOD_VALUE (1000000007)
class Solution {
public:
  /* 74.77, 81.85 */
  int numFactoredBinaryTrees(vector<int>& arr) {
    std::sort(arr.begin(), arr.end());
    unordered_map<int, int64_t> dp;
    dp[arr[0]] = 1;
    int64_t ans = 1;
    for (int i = 1; i < arr.size(); i++) {
      dp[arr[i]] = 1;
      for (int j = 0; j < i; j++) {
        if (arr[i] % arr[j] == 0 && dp.count(arr[i] / arr[j]) > 0) {
          dp[arr[i]] += dp[arr[j]] * dp[arr[i] / arr[j]];
        }
      }
      
      ans += dp[arr[i]];
    }
    return (int)(ans % MOD_VALUE);
  }
};
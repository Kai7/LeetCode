#include "utils/data_structure.hpp"
#include <algorithm>

class Solution {
public:
  /* 39.45, 81.72 */
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    std::sort(intervals.begin(), intervals.end(), [](vector<int> & a, vector<int> & b) -> bool {
      return a[0] < b[0];
    });
    int ans = 0;
    int cur = 0;
    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[cur][1] > intervals[i][0]) {
        ans += 1;
        if (intervals[cur][1] > intervals[i][1]) {
          cur = i;
        }
      } else {
        cur = i;
      }
    }
    return ans;
  }
};
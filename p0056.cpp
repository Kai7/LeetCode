#include "utils/data_structure.hpp"
#include <algorithm>

#define METHOD 0

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
class Solution {
public:
#if METHOD == 0
  /* 52.46, 84.66 */
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    std::sort(intervals.begin(), intervals.end(), [](vector<int> & a, vector<int> & b) -> bool {
      return a[0] < b[0];
    });
    vector<vector<int>> ans;
    ans.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++) {
      if (ans.back()[1] >= intervals[i][0]) {
        ans.back()[1] = MAX(ans.back()[1], intervals[i][1]);
      } else {
        ans.push_back(intervals[i]);
      }
    }
    return ans;
  }
#elif METHOD == 1
  /* Time Limit Exceeded */
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    std::sort(intervals.begin(), intervals.end(), [](vector<int> & a, vector<int> & b) -> bool {
      return a[0] < b[0];
    });
    auto it = intervals.begin();
    while (it != intervals.end()) {
      if (it + 1 == intervals.end()) break;
      auto next_it = it + 1;
      int intersection = MIN((*it)[1], (*next_it)[1]) - MAX((*it)[0], (*next_it)[0]);
      if (intersection >= 0) {
        (*it)[0] = MIN((*it)[0], (*next_it)[0]);
        (*it)[1] = MAX((*it)[1], (*next_it)[1]);
        intervals.erase(next_it);
      } else {
        it++;
      }
    }
    return intervals;
  }
#else
#endif
};
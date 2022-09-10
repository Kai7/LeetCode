#include "utils/data_structure.hpp"
#include <algorithm>
#include <iostream>

#define METHOD 0

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
class Solution {
public:
#if METHOD == 0
  /* 67.69, 91.94 */
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> ans;
    int cur = 0;
    while (cur < intervals.size() && newInterval[0] > intervals[cur][1]) {
      ans.push_back(intervals[cur++]);
    }
    while (cur < intervals.size() && newInterval[1] >= intervals[cur][0]) {
      newInterval[0] = MIN(newInterval[0], intervals[cur][0]);
      newInterval[1] = MAX(newInterval[1], intervals[cur][1]);
      cur++;
    }
    ans.push_back(newInterval);
    while (cur < intervals.size()) {
      ans.push_back(intervals[cur++]);
    }
    return ans;
  }
#elif METHOD == 2
  /* Wrong Answer */
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    if (intervals.size() == 0) {
      intervals.push_back(newInterval);
      return intervals;
    }
    /* linear search */
    for (int i = 0; i < intervals.size(); i++) {
      int intersection = MIN(intervals[i][1], newInterval[1]) - MAX(intervals[i][0], newInterval[0]);
      if (intersection >= 0) {
        intervals[i][0] = MIN(intervals[i][0], newInterval[0]);
        intervals[i][1] = MAX(intervals[i][1], newInterval[1]);
        int j = i + 1;
        while (j < intervals.size()) {
          intersection = MIN(intervals[i][1], intervals[j][1]) - MAX(intervals[i][0], intervals[j][0]);
          if (intersection < 0) break;
          intervals[i][0] = MIN(intervals[i][0], intervals[j][0]);
          intervals[i][1] = MAX(intervals[i][1], intervals[j][1]);
          j++;
        }
        intervals.erase(intervals.begin() + i + 1, intervals.begin() + j);
        return intervals;
      }

    }
    if (newInterval[0] < intervals[0][0]) {
      intervals.insert(intervals.begin(), newInterval);
    } else {
      intervals.push_back(newInterval);
    }
    return intervals;
  }
#elif METHOD == 1
  /* Wrong Answer */
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    if (intervals.size() == 0) {
      intervals.push_back(newInterval);
      return intervals;
    }
    std::sort(intervals.begin(), intervals.end(), [](vector<int> & a, vector<int> & b) -> bool {
      return a[0] < b[0];
    });
    auto it = intervals.begin();
    /* linear search */
    while (it != intervals.end()) {
      int intersection = MIN((*it)[1], newInterval[1]) - MAX((*it)[0], newInterval[0]);
      if (intersection >= 0) {
        (*it)[0] = MIN((*it)[0], newInterval[0]);
        (*it)[1] = MAX((*it)[1], newInterval[1]);
        while (it + 1 != intervals.end()) {
          auto next_it = it + 1;
          intersection = MIN((*it)[1], (*next_it)[1]) - MAX((*it)[0], (*next_it)[0]);
          if (intersection < 0) break;
          (*it)[0] = MIN((*it)[0], (*next_it)[0]);
          (*it)[1] = MAX((*it)[1], (*next_it)[1]);
          intervals.erase(next_it);
        }
        return intervals;
      }
      it++;
    }
    if (newInterval[0] < intervals[0][0]) {
      intervals.insert(intervals.begin(), newInterval);
    } else {
      intervals.push_back(newInterval);
    }
    return intervals;
  }
#else
#endif
};
#include "utils/data_structure.hpp"
#include <algorithm>

#define METHOD 0

class Solution {
public:
#if METHOD == 0
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int m = matrix.size(), n = matrix[0].size();
    int left = matrix[0][0], right = matrix[m - 1][n - 1];
    while (left < right) {
      int middle = left + (right - left) / 2;
      int rank = 0;
      int i = m - 1, j = 0;
      while (j < n) {
        while (i >= 0 && matrix[i][j] > middle) i--;
        if (i < 0) break;
        rank += i + 1;
        ++j;
      }
      if (rank < k) {
          left = middle + 1;
      }
      else {
          right = middle;
      }
    }
    return left;
  }

#elif METHOD == 7
  // TODO
  /* 98.58, 77.54 */
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int length = matrix.size(), lower = matrix[0][0], upper = matrix.back().back(), middle, lessThan;
    while (lower < upper) {
      middle = (lower + upper) >> 1;
      lessThan = 0;
      for (int i = 0, j = length - 1; i < length; ++i) {
        while (j >= 0 && middle < matrix[i][j])
            --j;
        lessThan += j + 1;
      }
      if (lessThan < k)
        lower = middle + 1;
      else
        upper = middle;
    }
    return lower;
  }
#elif METHOD == 6
  /* 23.07, 53.70 */
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    priority_queue<int> q;
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[0].size(); j++) {
        q.push(matrix[i][j]);
        if (q.size() > k) {
          q.pop();
        }
      }
    }
    return q.top();
  }
#elif METHOD == 5
  /* 50.35, 99.39 */
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int left = matrix[0][0], right = matrix.back().back();
    while (left < right) {
      int mid = left + (right - left) / 2;
      int cnt = search_less_equal(matrix, mid);
      if (cnt < k) left = mid + 1;
      else right = mid;
    }
    return left;
  }
  int search_less_equal(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), i = n - 1, j = 0, res = 0;
    while (i >= 0 && j < n) {
      if (matrix[i][j] <= target) {
        res += i + 1;
        ++j;
      } else {
        --i;
      }
    }
    return res;
  }
#elif METHOD == 4
  /* 35.25, 59.46 */
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int left = matrix[0][0], right = matrix.back().back();
    while (left < right) {
      int mid = left + (right - left) / 2, cnt = 0;
      for (int i = 0; i < matrix.size(); ++i) {
        cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
      }
      if (cnt < k) left = mid + 1;
      else right = mid;
    }
    return left;
  }

#elif METHOD == 3
  /* TODO: FIX ME */
  int findRank(vector<int>& nums, int value) {
    int left = 0;
    int right = nums.size() - 1;
    while (left < right) {
      int m = (left + right) / 2;
      if (value <= nums[m]) {
        right = m;
      } else {
        left = m + 1;
      }
    }

    return (value > nums[left]) ? left + 1 : left;
  }

  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int min = matrix[0][0];
    int max = matrix[n - 1][n - 1];
    while (min < max) {
      int middle = (min + max) / 2;
      int rank = 0;
      for (int i = 0; i < n; ++i) {
        int r = findRank(matrix[i], middle);
        rank += r;
      }
      if (rank >= k - 1) {
        max = middle - 1;
      } else {
        min = middle;
      }
    }
    return min;
  }

#elif METHOD == 2
  /* TODO: FIX ME */
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    std::vector<int> idx(n, 0);
    std::vector<std::pair<int, int>> min_values(n);
    for (int i = 0; i < n; ++i) {
      min_values[i] = std::pair<int, int>(matrix[i][0], i);
    }
    std::sort(min_values.begin(), min_values.end(), 
              [](const std::pair<int, int> &a, const std::pair<int, int> &b) -> bool {
                return a.first > b.first;
              });
    int counter = 0;
    int ans;
    while (counter < k) {
      ans = min_values[0].first;
      int i = idx[min_values[0].second];
      ++idx[i]; 
      min_values.erase(min_values.begin());
      if (idx[i] == n) {
        ++counter;
        continue;
      }
      auto it = std::lower_bound(min_values.begin(), min_values.end(), matrix[i][idx[i]], 
                                 [](std::pair<int, int> a, int val) -> bool { 
                                   return a.first < val; 
                                 });
      min_values.insert(it, std::pair<int, int>(matrix[i][idx[i]], i));
      ++counter;
    }
    return ans;
  }
#elif METHOD == 1
  /* 5.03, 92.86 */
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    vector<int> idx(n, 0);
    int counter = 0;
    int min_value;
    while (counter < k) {
      int min_i;
      for (int i = 0; i < n; ++i) {
        if (idx[i] < n) {
          min_i = i;
          min_value = matrix[i][idx[i]];
          break;
        }
      }
      for (int i = min_i; i < n; ++i) {
        if (idx[i] >= n) continue;
        if (matrix[i][idx[i]] < min_value) {
          min_i = i;
          min_value = matrix[i][idx[i]];
        }
      }
      ++idx[min_i];
      ++counter;
    }
    return min_value;
  }
#else
#endif
};
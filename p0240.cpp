#include "utils/data_structure.hpp"

class Solution {
public:
  /* 28.27, 21.59 */
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int i = m - 1, j = 0;
    while (i >= 0 && j >= 0 && i < m && j < n) {
      if (matrix[i][j] == target) return true;
      if (matrix[i][j] > target) --i;
      else ++j;
    }
    return false;
  }
};
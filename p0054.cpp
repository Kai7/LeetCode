#include "utils/data_structure.hpp"

class Solution {
public:
  /* 6.05, 30.48 */
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> ans;
    int top = 0, left = 0, bottom = m - 1, right = n - 1;

    while (top <= bottom && left <= right) {
      for (int j = left; j <= right; j++) {
        ans.push_back(matrix[top][j]);
      }
      if (++top > bottom) break;
      for (int i = top; i <= bottom; i++) {
        ans.push_back(matrix[i][right]);
      }
      if (--right < left) break;
      for (int j = right; j >= left; j--) {
        ans.push_back(matrix[bottom][j]);
      }
      if (--bottom < top) break;
      for (int i = bottom; i >= top; i--) {
        ans.push_back(matrix[i][left]);
      }
      left++;
    }
    return ans;
  }
};
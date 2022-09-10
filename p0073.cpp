#include "utils/data_structure.hpp"

class Solution {
public:
  /* 12.48, 52.88 */
  void setZeroes(vector<vector<int>>& matrix) {
    bool set_first_row_zero = false;
    bool set_first_col_zero = false;
    int m = matrix.size();
    int n = matrix[0].size();
    for (int j = 0; j < n; j++) {
      if (matrix[0][j] == 0) {
        set_first_row_zero = true;
        break;
      }
    }
    for (int i = 0; i < m; i++) {
      if (matrix[i][0] == 0) {
        set_first_col_zero = true;
        break;
      }
    }
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (matrix[i][j] == 0) {
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }
      }
    }
    for (int i = 1; i < m; i++) {
      if (matrix[i][0] == 0) {
        for (int j = 1; j < n; j++) {
          matrix[i][j] = 0;
        }
      }
    }
    for (int j = 1; j < n; j++) {
      if (matrix[0][j] == 0) {
        for (int i = 1; i < m; i++) {
          matrix[i][j] = 0;
        }
      }
    }
    if (set_first_row_zero) {
      for (int j = 0; j < n; j++) {
        matrix[0][j] = 0;
      }
    }
    if (set_first_col_zero) {
      for (int i = 0; i < m; i++) {
        matrix[i][0] = 0;
      }
    }
  }
};
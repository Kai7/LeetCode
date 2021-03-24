#include "utils/data_structure.hpp"
#include <iostream>
#include "stdio.h"

class Solution {
public:
  /* Accepted: 59.74, 55.25 */
  void rotate(vector<vector<int>>& matrix) {
    size_t n = matrix.size();
    for (size_t i = 0; i < n / 2; i++){
      for (size_t j = i; j < n - 1 - i; j++) {
        int tmp = matrix[i][j];
        matrix[i][j] = matrix[n-1-j][i];
        matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
        matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
        matrix[j][n-1-i] = tmp;
      }
    }
  }
};
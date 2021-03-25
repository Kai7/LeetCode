#include "utils/data_structure.hpp"
#include <iostream>

class Solution {
public:
  /* Accepted: 98.05, 16.57 */
  void setZeroes(vector<vector<int>>& matrix) {
    bool *row = new bool[matrix.size()]();
    bool *col = new bool[matrix[0].size()]();
    for (size_t i = 0; i < matrix.size(); i++){
      for (size_t j = 0; j < matrix[0].size(); j++){
        if (matrix[i][j] == 0) {
          row[i] = true;
          col[j] = true;
        }
      }
    }
    for (size_t i = 0; i < matrix.size(); i++){
      for (size_t j = 0; j < matrix[0].size(); j++){
        if (row[i] || col[j]) matrix[i][j] = 0;
      }
    }
    delete [] row;
    delete [] col;
  }
};
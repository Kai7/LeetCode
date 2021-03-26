#include "utils/data_structure.hpp"
#include <iostream>

class Solution {
public:
  /* Accepted: 100.00, 93.83 */
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (target < matrix[0][0]) return false;
    size_t i_front = 0, i_rear = matrix.size() - 1;
    size_t j_front = 0, j_rear = matrix[0].size() - 1;
    while (i_front != i_rear){
      size_t i_mid = (i_front + i_rear + 1) / 2;
      if (target < matrix[i_mid][0]) i_rear = i_mid - 1;
      else i_front = i_mid;
    }
    if (target > matrix[i_front][j_rear]) return false;
    while (j_front != j_rear){
      size_t j_mid = (j_front + j_rear) / 2;
      if (target > matrix[i_front][j_mid]) j_front = j_front + 1;
      else j_rear = j_mid;
    }
    if (target != matrix[i_front][j_rear]) return false;
    return true;
  }
};
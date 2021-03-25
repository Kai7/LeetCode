#include "utils/data_structure.hpp"
#include <iostream>
#include "stdio.h"

class Solution {
public:
  /* Accepted: 100.00, 84.29 */
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int top = 0, down = static_cast<int>(matrix.size()) - 1;
    int left = 0, right = static_cast<int>(matrix[0].size()) - 1;
    while (top <= down && left <= right) {
      for (int j = left; j <= right; j++){
        ans.push_back(matrix[top][j]);
      }
      top += 1;
      for (int i = top; i <= down; i++){
        ans.push_back(matrix[i][right]);
      }
      right -= 1;
      if (top > down || left > right) break;
      for (int j = right; j >= left; j--){
        ans.push_back(matrix[down][j]);
      }
      down -= 1;
      for (int i = down; i >= top; i--){
        ans.push_back(matrix[i][left]);
      }
      left += 1;
    }
    return ans;
  }
};
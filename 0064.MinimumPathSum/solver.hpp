#include "utils/data_structure.hpp"
#include <iostream>

#define MIN(a,b) (((a)<(b))?(a):(b))

#define METHOD 0

class Solution {
public:
#if METHOD == 0
  int minPathSum(vector<vector<int>>& grid) {
    int r = static_cast<int>(grid.size());
    int c = static_cast<int>(grid[0].size());
    int **table = new int*[2];
    table[0] = new int[r];
    table[1] = new int[r];

    table[0][0] = grid[0][0];
    for (int i = 1; i < r; ++i){
      table[0][i] = table[0][i-1] + grid[i][0];
    }
    for (int j = 1; j < c; ++j){
      int p = 1 - (j % 2);
      int q = 1 - p;
      table[q][0] = table[p][0] + grid[0][j];
      for (int i = 1; i < r; ++i){
        table[q][i] = MIN(table[q][i-1], table[p][i]) + grid[i][j];
      }
    }
    int ans = table[ 1 - (c % 2)][r-1];
    delete [] table[0];
    delete [] table[1];
    return ans;
  }

#elif METHOD == 1
  /* Accepted: 98.76, 36.06 */
  int minPathSum(vector<vector<int>>& grid) {
    int row = static_cast<int>(grid.size());
    int col = static_cast<int>(grid[0].size());
    int **min_sum = new int*[row];
    for (int i = 0; i < row; i++) min_sum[i] = new int[col];
    min_sum[0][0] = grid[0][0];
    for (int t = 1; t <= row + col - 2; t++){
      for (int i = 0; i <=t; i ++){
        if (i >= row) continue;
        int j = t - i;
        if (j >= col) continue;
        if (i == 0) min_sum[i][j] = grid[i][j] + min_sum[i][j-1];
        else if (j == 0) min_sum[i][j] = grid[i][j] + min_sum[i-1][j];
        else min_sum[i][j] = grid[i][j] + MIN(min_sum[i-1][j], min_sum[i][j-1]);
      }
    }
    int ans = min_sum[row - 1][col - 1];
    for (int i = 0; i < row; i++) delete [] min_sum[i];
    delete [] min_sum;
    return ans;
  }
#else
#error ""
#endif
};
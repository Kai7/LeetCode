#include "utils/data_structure.hpp"

#define METHOD 0

class Solution {
public:
#if METHOD == 0
  /* 27.09, 94.16 */
  int rows, cols;

  void dfs(vector<vector<int>>& heights, std::vector<std::vector<bool>>& visited, int i, int j, int source) {
    if (i < 0 || i >= rows || j < 0 || j >= cols) return;
    if (visited[i][j]) return;
    if (heights[i][j] < source) return;
    visited[i][j] = true;
    dfs(heights, visited, i - 1, j, heights[i][j]);
    dfs(heights, visited, i + 1, j, heights[i][j]);
    dfs(heights, visited, i, j - 1, heights[i][j]);
    dfs(heights, visited, i, j + 1, heights[i][j]);
  }
  
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    vector<vector<int>> ans;
    rows = heights.size();
    cols = heights[0].size();
    std::vector<std::vector<bool>> pacific(rows, vector<bool>(cols, false));
    std::vector<std::vector<bool>> atlantic(rows, vector<bool>(cols, false));
    for (int j = 0; j < cols; ++j) {
      dfs(heights, pacific, 0, j, INT32_MIN);
      dfs(heights, atlantic, rows - 1, j, INT32_MIN);
    }
    for (int i = 0; i < rows; ++i) {
      dfs(heights, pacific, i, 0, INT32_MIN);
      dfs(heights, atlantic, i, cols - 1, INT32_MIN);
    }
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (pacific[i][j] && atlantic[i][j]) {
          ans.emplace_back(vector<int>({i, j}));
        }
      }
    }
    return ans;
  }
#else
#endif
};
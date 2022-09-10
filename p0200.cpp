#include "utils/data_structure.hpp"
#include <functional>

#define METHOD 0

class Solution {
public:

#if METHOD == 0
  /* 12.02, 20.49 */
  int numIslands(vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int res = 0;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    queue<pair<int, int>> q;
    std::function<void()> bfs;
    bfs = [&bfs, &grid, &visited, &m, &n, &q] () {
      pair<int, int> p = q.front();
      q.pop();
      if (p.first < 0 || p.second < 0 || p.first >= m || p.second >= n) return;
      if (visited[p.first][p.second] || grid[p.first][p.second] == '0') return;
      visited[p.first][p.second] = true;
      q.push({p.first - 1, p.second});
      q.push({p.first + 1, p.second});
      q.push({p.first, p.second - 1});
      q.push({p.first, p.second + 1});
    };
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '1' && !visited[i][j]) {
          res++;
          q.push({i, j});
          while(!q.empty()) bfs();
        }
      }
    }
    return res;
  }
#elif METHOD == 1
  /* 43.51, 34.15 */
  int numIslands(vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int res = 0;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    std::function<void(int,int)> dfs;
    dfs = [&dfs, &grid, &visited, &m, &n] (int i, int j) {
      if (i < 0 || j < 0 || i >= m || j >= n) return;
      if (visited[i][j] || grid[i][j] == '0') return;
      visited[i][j] = true;
      dfs(i - 1, j);
      dfs(i + 1, j);
      dfs(i, j - 1);
      dfs(i, j + 1);
    };
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '1' && !visited[i][j]) {
          res++;
          dfs(i, j);
        }
      }
    }
    return res;
  }
#elif METHOD == 1
  /* 28.81, 39.11 */
  int m, n;
  void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
    if (i < 0 || j < 0 || i >= m || j >= n) return;
    if (grid[i][j] == '0') return;
    if (visited[i][j]) return;
    visited[i][j] = true;
    dfs(grid, visited, i - 1, j);
    dfs(grid, visited, i + 1, j);
    dfs(grid, visited, i, j - 1);
    dfs(grid, visited, i, j + 1);
  }
  int numIslands(vector<vector<char>>& grid) {
    m = grid.size();
    n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int ans = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == '1' && !visited[i][j]) {
          dfs(grid, visited, i, j);
          ++ans;
        }
      }
    }
    return ans;
  }
#else
#endif
};
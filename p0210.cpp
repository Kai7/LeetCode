#include "utils/data_structure.hpp"

class Solution {
public:
  /* 96.12, 80.44 */
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> ans;
    vector<vector<int>> graph(numCourses, vector<int>({}));
    vector<int> in_degree(numCourses, 0);
    for (int i = 0; i < prerequisites.size(); ++i) {
      ++in_degree[prerequisites[i][0]];
      graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }
    queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
      if (in_degree[i] == 0) q.push(i);
    }
    int counter = 0;
    while (!q.empty()) {
      ++counter;
      int i = q.front();
      q.pop();
      ans.push_back(i);
      for (const int& j: graph[i]) {
        --in_degree[j];
        if (in_degree[j] == 0) q.push(j);
      }
    }
    if (counter == numCourses) {
      return ans;
    } else {
      return vector<int>({});
    }
  }
};
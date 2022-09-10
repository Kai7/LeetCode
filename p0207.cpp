#include "utils/data_structure.hpp"

#define METHOD 0

class Solution {
#if METHOD == 0
public:
  /* 83.17, 88.02 */
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
      for (const int& j: graph[i]) {
        --in_degree[j];
        if (in_degree[j] == 0) q.push(j);
      }
    }
    return counter == numCourses;
  }
#elif METHOD == 1
  /* 83.17, 88.02 */
  class CourseNode {
  public:
    int reqNum;
    vector<int> nextID;
    CourseNode() : reqNum(0), nextID({}) {};
  };
public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    queue<int> q;
    vector<CourseNode> courses(numCourses);
    for (int i = 0; i < prerequisites.size(); i++) {
      ++courses[prerequisites[i][0]].reqNum;
      courses[prerequisites[i][1]].nextID.push_back(prerequisites[i][0]);
    }
    for (int i = 0; i < courses.size(); i++) {
      if (courses[i].reqNum == 0) q.push(i);
    }
    int counter = 0;
    while (!q.empty()) {
      counter++;
      int i = q.front();
      q.pop();
      for (const int& j: courses[i].nextID) {
        --courses[j].reqNum;
        if (courses[j].reqNum == 0) q.push(j);
      }
    }
    return counter == numCourses;
  }
#else
#endif
};
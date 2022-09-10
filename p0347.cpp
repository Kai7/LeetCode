#include "utils/data_structure.hpp"

#define METHOD 0

class Solution {
public:

#if METHOD == 0
  /* 86.35, 89.17 */
  vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> ans;
    unordered_map<int, int> counter;
    priority_queue<pair<int, int>> pq;
    for (const int & n: nums) {
      ++counter[n];
    }
    for (auto it: counter) {
      pq.push({it.second, it.first});
    }
    for (int i = 0; i < k; ++i) {
      ans.push_back(pq.top().second);
      pq.pop();
    }
    return ans;
  }
#elif METHOD == 1
  /* 67.31, 97.64 */
  vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> ans;
    unordered_map<int, int> counter;
    for (const int & n: nums) {
      counter[n]++;
    }
    auto cmp = [](pair<int, int> & a, pair<int, int> & b) -> bool {
      return a.second > b.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    auto it = counter.begin();
    while (it != counter.end()) {
      pq.push(pair<int, int>(it->first, it->second));
      ++it;
    }
    for (int i = 0; i < k; ++i) {
      pair<int, int> t = pq.top();
      pq.pop();
      ans.push_back(t.first);
    }
    return ans;
  }
#else
#endif
};
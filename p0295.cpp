#include "utils/data_structure.hpp"

#define METHOD 0

class MedianFinder {
public:
#if METHOD == 0
  /* 90.58, 89.57 */
  MedianFinder() {}
  void addNum(int num) {
    if (min_queue.empty()) {
      min_queue.push(num);
      return;
    }
    if (min_queue.size() == max_queue.size()) {
      if (num > max_queue.top()) {
        min_queue.push(max_queue.top());
        max_queue.pop();
        max_queue.push(num);
      } else {
        min_queue.push(num);
      }
    } else {
      if (num < min_queue.top()) {
        max_queue.push(min_queue.top());
        min_queue.pop();
        min_queue.push(num);
      } else {
        max_queue.push(num);
      }
    }
  }
  double findMedian() {
    if (min_queue.size() == max_queue.size()) {
      return (min_queue.top() + max_queue.top()) / 2.0;
    }
    return min_queue.top();
  }
private:
  priority_queue<int> min_queue;
  priority_queue<int, vector<int>, std::greater<int>> max_queue;

#elif METHOD == 2
  /* 5.05, 89.22 */
  MedianFinder() {}
  void addNum(int num) {
    min_queue.push(num);
    max_queue.push(min_queue.top());
    min_queue.pop();
    if (max_queue.size() > min_queue.size()) {
      min_queue.push(max_queue.top());
      max_queue.pop();
    }
  }
  double findMedian() {
    if (min_queue.size() == max_queue.size()) {
      return (min_queue.top() + max_queue.top()) / 2.0;
    }
    return min_queue.top();
  }
private:
  priority_queue<int> min_queue;
  priority_queue<int, vector<int>, std::greater<int>> max_queue;

#elif METHOD == 1
  /* Time Limit Exceeded */
  vector<int> data;
  MedianFinder() {}
  
  void addNum(int num) {
    if (data.size() == 0) {
      data.push_back(num);
      return;
    }
    int l = 0, r = data.size() - 1;
    while (l < r) {
      int m = (l + r) / 2;
      if (num <= data[m]) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    data.insert(data.begin() + l + ((num >= data[l]) ? 1 : 0), num);
  }
  
  double findMedian() {
    if (data.size() % 2 != 0) {
      return data[data.size() / 2];
    }
    return (float)(data[data.size() / 2 - 1] + data[data.size() / 2]) / 2; 
  }
#else
#endif
};
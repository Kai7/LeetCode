#include <vector>
using std::vector;
#include <iostream>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

class Solution {
public:
  int maxArea(vector<int>& height) {
    size_t ans = 0;
    size_t front = 0, rear = height.size() - 1;
    while (rear > front) {
      ans = MAX(ans, MIN(height[front], height[rear]) * (rear - front));
      if (height[front] < height[rear]){
        front++;
      } else {
        rear--;
      }
    }
    return static_cast<int>(ans);
  }

#if 0
  /* O(n^2), Time Limit Exceeded */
  int maxArea(vector<int>& height) {
    int ans = 0;
    for (size_t i = 0; i < height.size() - 1 ; i++) {
      for (size_t j = i + 1; j < height.size(); j++) {
        int area = static_cast<int>(MIN(height[i], height[j]) * (j - i));
        if (area > ans) ans = area;
      }
    }
    return ans;
  }
#endif
};
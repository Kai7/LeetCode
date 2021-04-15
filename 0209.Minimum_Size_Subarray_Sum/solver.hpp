#include "utils/data_structure.hpp"
#include <iostream>
#include "stdio.h"


#define MIN(a,b) (((a)<(b))?(a):(b))

class Solution {
public:
  /* Accepted: 100.00, 59.25 */
  int minSubArrayLen(int target, vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int front = 0, rear = 0;
    int current_sum = nums[0];
    while (current_sum < target && rear < static_cast<int>(nums.size()) - 1){
      rear += 1;
      current_sum += nums[rear];
    }
    if (current_sum < target) return 0;
    if (front == rear) return 1;
    int ans = rear - front + 1;
    while (front < static_cast<int>(nums.size()) - 1){
      current_sum -= nums[front];
      front += 1;
      if (front > rear) {
        rear += 1;
        current_sum += nums[rear];
      }
      if (current_sum > target) {
        ans = MIN(ans, rear - front + 1);
        if (ans == 1) return 1;
        continue;
      }
      while (current_sum < target && rear < static_cast<int>(nums.size()) - 1){
        rear += 1;
        current_sum += nums[rear];
      }
      if (current_sum < target) return ans;
      ans = MIN(ans, rear - front + 1);
    }
    return ans;
  }
};
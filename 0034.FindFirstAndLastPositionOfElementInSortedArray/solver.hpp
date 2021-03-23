#include "utils/data_structure.hpp"
#include <iostream>
#include "stdio.h"

#define MAX(a,b) (((a)>(b))?(a):(b))

class Solution {
public:
  /* TODO: Review */
  /* Accepted: 82.39, 50.14 */
  vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.size() == 0) {
      vector<int> ans = {-1,-1};
      return ans;
    }
    size_t front = 0, rear = nums.size() - 1;
    size_t first = (front + rear) / 2;
    while (front < rear){
      // printf("  first: %lu [ %lu, %lu]\n", first, front, rear);
      if (nums[first] == target) {
        if (first == 0 || nums[first-1] != nums[first]) break;
        rear = MAX(0, (static_cast<int>(first) - 1));
      } else if (nums[first] < target) {
        front = first + 1;
      } else {
        rear = MAX(0, (static_cast<int>(first) - 1));
      }
      first = (front + rear) / 2;
    }
    // printf("  first: %lu [ %lu, %lu]\n", first, front, rear);
    if (nums[first] != target) {
      vector<int> ans = {-1,-1};
      return ans;
    }
    front = first;
    rear = nums.size() - 1;
    size_t second = (front + rear + 1) / 2;
    while (front < rear){
      // printf("  second: %lu [ %lu, %lu]\n", second, front, rear);
      if (nums[second] == target) {
        if (second == nums.size() - 1 || nums[second+1] != nums[second]) break;
        front = second + 1;
      } else if (nums[second] > target) {
        rear = MAX(0, (static_cast<int>(second) - 1));
      } else {
        front = second + 1;
      }
      second = (front + rear + 1) / 2;
    }
    vector<int> ans = {static_cast<int>(first), static_cast<int>(second)};
    return ans;
  }
};
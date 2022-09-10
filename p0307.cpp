#include "utils/data_structure.hpp"
#include <cmath>

#define METHOD 0

/**
 * TODO:
 *   Segment Tree 
 *   https://zxi.mytechroad.com/blog/data-structure/307-range-sum-query-mutable/
 */

class NumArray {
public:
#if METHOD == 0
  /* 9.41, 71.54 */
  NumArray(vector<int> nums) {
    if (nums.empty()) return;
    data = nums;
    double root = sqrt(data.size());
    len = ceil(data.size() / root);
    block.resize(len);
    for (int i = 0; i < data.size(); ++i) {
        block[i / len] += data[i];
    }
  }
  
  void update(int i, int val) {
    int idx = i / len;
    block[idx] += val - data[i];
    data[i] = val;
  }
  
  int sumRange(int i, int j) {
    int sum = 0;
    int start = i / len, end = j / len;
    if (start == end) {
      for (int k = i; k <= j; ++k) {
          sum += data[k];
      }
      return sum;
    }
    for (int k = i; k < (start + 1) * len; ++k) {
      sum += data[k];
    }
    for (int k = start + 1; k < end; ++k) {
      sum += block[k];
    }
    for (int k = end * len; k <= j; ++k) {
      sum += data[k];
    }
    return sum;
  }
  
private:
    int len;
    vector<int> data, block;

#elif METHOD == 1
  /* Time Limit Exceeded */
  NumArray(vector<int>& nums) {
    _nums = vector<int>(nums.begin(), nums.end());
    _dp = _nums;
    for (int i = 1; i < _dp.size(); ++i) {
      _dp[i] += _dp[i - 1];
    }
  }
  
  void update(int index, int val) {
    int diff = val - _nums[index];
    for (int i = index; i < _dp.size(); ++i) {
      _dp[i] += diff;
    }
    _nums[index] = val;
  }
  
  int sumRange(int left, int right) {
      if (left == 0) return _dp[right];
      return _dp[right] - _dp[left - 1];
  }
private: 
  vector<int> _nums;
  vector<int> _dp;
#else
#endif
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
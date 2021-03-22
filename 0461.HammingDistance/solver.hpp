#include "utils/data_structure.hpp"
#include <iostream>

class Solution {
public:
  int hammingDistance(int x, int y) {
    uint32_t d = x ^ y;
    int ans = 0;
    for (int i = 1; i <= 32; i++) {
      ans += (d << (32 - i)) >> 31;
    }
    return ans;
  }
};
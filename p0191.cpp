#include "utils/data_structure.hpp"

class Solution {
public:
  int c = 0;
  int hammingWeight(uint32_t n) {
  if(n == 0) return c;
	if((uint32_t)(n & 1) == 1) c++;
    return hammingWeight( n>>1);
  }

#if 0
  int hammingWeight(uint32_t n) {
    int ans = 0;
    for (int i = 0; i < 32; i++) {
      uint32_t mask = 1 << i;
      if ((uint32_t)(n & mask) > 0) ans += 1;
    }
    return ans;
  }
#endif
};
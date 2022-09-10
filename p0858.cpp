#include "utils/data_structure.hpp"

class Solution {
public:
  /* 100.00, 26.45 */
  int mirrorReflection(int p, int q) {
    while (p % 2 == 0 && q % 2 == 0) {
      p /= 2; q /= 2;
    }
    if (p % 2 == 0) return 2;
    if (q % 2 == 0) return 0;
    return 1;
  }
};
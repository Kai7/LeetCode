#include "utils/data_structure.hpp"
#include <iostream>

#define MIN(a,b) (((a)<(b))?(a):(b))

class Solution {
public:
  // TODO: Use DP

  /* How it work??? */
  /* Accepted: 100.00, 97.74 */
  int uniquePaths(int m, int n) {
    int min = MIN(m - 1,n - 1), sum = m + n - 2;
    long numerator = 1, denominator = 1;
    for (int i = 1; i <= min; i++) {
      numerator *= i;
      denominator *= sum - i + 1;
      if (denominator > INT32_MAX){
        while(denominator % 2 == 0 && numerator % 2 == 0){
          denominator /= 2;
          numerator /= 2;
        }
        while(denominator % 3 == 0 && numerator % 3 == 0){
          denominator /= 3;
          numerator /= 3;
        }
      }
    }
    return static_cast<int>(denominator / numerator);
  }
#if 0
  /* Runtime Error */
  int uniquePaths(int m, int n) {
    int min = MIN(m - 1,n - 1), sum = m + n - 2;
    int numerator = 1, denominator = 1;
    for (int i = 1; i <= min; i++) {
      numerator *= i;
      denominator *= sum - i + 1;
    }
    return denominator / numerator;
  }
#endif
};
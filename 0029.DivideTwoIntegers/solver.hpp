#include <iostream>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

class Solution {
public:
  int divide(int dividend, int divisor) {
    long denominator = static_cast<long>(dividend);
    long numerator = static_cast<long>(divisor);
    bool is_positive = true;
    if (denominator < 0) {
      denominator = 0 - denominator;
      is_positive = !is_positive;
    }
    if (numerator < 0) {
      numerator = 0 - numerator;
      is_positive = !is_positive;
    }
    long quotient = 0;
    for (int i = 31; i >= 0; i--){
      quotient = quotient << 1;
      if (denominator >= numerator << i) {
        denominator -= numerator << i;
        quotient += 1;
      }
    }
    if (is_positive) {
      quotient = MIN(quotient, INT32_MAX);
      return static_cast<int>(quotient);
    } 
    return static_cast<int>(0 - quotient);
  }

#if 0
  /* Time Limit Exceeded */
  int divide(int dividend, int divisor) {
    if (dividend == divisor) return 1;
    if (dividend == (int) 0x80000000 && divisor == -1) return (int) 0x7FFFFFFF;
    if (divisor == 1) return dividend;
    if (divisor == -1) return 0 - dividend;
    int ans = 0;
    if (dividend > 0) {
      if (divisor > 0) {
        dividend -= divisor;
        while (dividend >= 0) {
          ans += 1;
          dividend -= divisor;
        }
        return ans;
      } else {
        dividend += divisor;
        while (dividend >= 0) {
          ans += 1;
          dividend += divisor;
        }
        return 0 - ans;
      }
    } else {
      if (divisor > 0) {
        dividend += divisor;
        while (dividend <= 0) {
          ans += 1;
          dividend += divisor;
        }
        return 0 - ans;
      } else {
        dividend -= divisor;
        while (dividend <= 0) {
          ans += 1;
          dividend -= divisor;
        }
        return ans;
      }
    }
  }
#endif

#if 0
  /* Runtime Error */
  /* Wrong Answer: Because using multiplication, division, or mod operator.*/
  int divide(int dividend, int divisor) {
    int ans = 0, sign = 1;
    if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
      sign = -1;
    }      
    dividend = (dividend >= 0)? dividend : -1 * dividend;
    divisor = (divisor >= 0)? divisor : -1 * divisor;

    dividend -= divisor;
    while (dividend >= 0) {
      ans += 1;
      dividend -= divisor;
    }
    return ans * sign;
  }
#endif 
};
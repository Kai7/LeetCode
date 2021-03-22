#include "utils/data_structure.hpp"
#include <iostream>

class Solution {
public:
  double myPow(double x, int n) {
    if (n == 0) return 1.0;
    long m = static_cast<long>(n);
    m = (m > 0) ? m : -1 * m;
    vector<double> lookup_table = {1.0};
    long c = 1, idx = 1;
    double xc = x;
    while (c <= m) {
      lookup_table.push_back(xc);
      c *= 2;
      idx += 1;
      xc *= xc;
    }
    double ans = 1.0;
    while (m > 0) {
      if ((m - c) >= 0) {
        ans *= lookup_table[idx];
        m -= c;
      }
      c /= 2;
      idx -= 1;
    }
    if (n > 0) return ans;
    return 1.0 / ans;
  }

#if 0
  /* Time Limit Exceeded */
  double myPow(double x, int n) {
    if (n == 0) return 1.0;
    int m = (n > 0) ? n : -1 * n;
    double ans = 1.0;
    for (int i = 1; i <= m; i++)
      ans *= x;
    if (n > 0) return ans;
    return 1.0 / ans;
  }
#endif
};
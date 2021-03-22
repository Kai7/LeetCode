#include "solver.hpp"
#include "utils/data_structure.hpp"
#include "utils/utils.hpp"

void runSample(double x, int n) {
  std::cout << "Input: x = " << x << ", n = " << n << std::endl;
  Solution solver;
  double ans = solver.myPow(x, n);
  std::cout << "Output: " << ans << std::endl << std::endl;
}

int main(){
  runSample(2.0, 10);
  runSample(2.0, 0);
  runSample(-2.0, -3);
  runSample(0.86429, 18);
  runSample(0.00001, 2147483647);
  runSample(1.0, -2147483648);

  return 0;
}
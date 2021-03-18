#include "solver.hpp"

#include "utils/utils.hpp"

void runSample(vector<int>& height) {
  Solution solver;
  int ans = solver.maxArea(height);
  std::cout << "Input: height = " << vector2str(height) << std::endl;
  std::cout << "Output: " << ans << std::endl;
}

int main(int argc, char **argv) {
  vector<int> t1 = {1,8,6,2,5,4,8,3,7};
  vector<int> t2 = {4,3,2,1,4};
  vector<int> t3 = {1,2,1};

  runSample (t1);
  runSample (t2);
  runSample (t3);

  return 0;
}
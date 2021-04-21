#include "solver.hpp"
#include "utils/data_structure.hpp"
#include "utils/utils.hpp"

void runSample(vector<int>& nums, int k){
  std::cout << "Input: nums = " << toString(nums) << ", k = " << k << std::endl;
  Solution solver;
  vector<int> ans = solver.maxSlidingWindow(nums, k);
  std::cout << "Output: " << toString(ans) << std::endl;
}

int main(){
  vector<int> nums = createVector_Random(15);
  // vector<int> nums = {-7,-8,7,5,7,1,6,0};

  runSample(nums, 1);
  runSample(nums, 2);
  runSample(nums, 3);
  runSample(nums, 4);
  runSample(nums, 5);

  return 0;
}
#include "solver.hpp"
#include "utils/data_structure.hpp"
#include "utils/utils.hpp"

void runSample(int target, vector<int>& nums) {
  std::cout << "Input: target = " << target << ", nums = " << toString(nums) << std::endl;
  Solution solver;
  int ans = solver.minSubArrayLen(target, nums);
  std::cout << "Output: " << ans << std::endl << std::endl;
}

int main(){
  // int target = 7;
  // vector<int> nums = {2,3,1,2,4,3};
  // int target = 1;
  // vector<int> nums = {1,4,4};
  int target = 11;
  // vector<int> nums = {1,1,1,1,1,1,1,1,1,1,1};
  vector<int> nums = {1,1,1,1,1,1,1,1,1};

  runSample(target, nums);

  return 0;
}
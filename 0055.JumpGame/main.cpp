#include "solver.hpp"
#include "utils/data_structure.hpp"
#include "utils/utils.hpp"

void runSample(vector<int>& nums){
  std::cout << "Input: nums = " << toString(nums) << std::endl;
  Solution solver;
  bool ans = solver.canJump(nums);
  std::cout << "Output: " << ans << std::endl << std::endl;
}

int main(){
  // vector<int> nums = {2,3,1,1,4};
  // vector<int> nums = {3,2,1,0,4};
  // vector<int> nums = {2,0};
  vector<int> nums = {3,0,8,2,0,0,1};

  runSample(nums);

  return 0;
}
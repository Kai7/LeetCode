#include "solver.hpp"
#include "utils/data_structure.hpp"
#include "utils/utils.hpp"

void runSample(vector<int>& nums){
  std::cout << "Input: nums = " << toString(nums) << std::endl;
  Solution solver;
  vector<vector<int>> ans = solver.permute(nums);
  std::cout << "Output: " << toString(ans) << std::endl << std::endl;
}

int main(){
  vector<int> nums = {1,2,3};
  // vector<int> nums = {1,2};
  // vector<int> nums = {1};

  runSample(nums);

  return 0;
}
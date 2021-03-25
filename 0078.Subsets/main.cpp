#include "solver.hpp"
#include "utils/data_structure.hpp"
#include "utils/utils.hpp"

void runSample(vector<int>& nums){
  std::cout << "Input: nums = " << toString(nums) << std::endl;
  Solution solver;
  vector<vector<int>> ans = solver.subsets(nums);
  std::cout << "Output: " << toString(ans) << std::endl << std::endl;
}

int main(){
  vector<int> nums = {1,2,3,4,5};

  runSample(nums);

  return 0;
}
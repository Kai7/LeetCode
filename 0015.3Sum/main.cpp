#include "solver.hpp"
#include "utils/utils.hpp"

void runSample(vector<int>& nums){
  Solution solver;
  vector<vector<int>> ans = solver.threeSum(nums);
  std::cout << "Input: nums = " << toString(nums) << std::endl;
  std::cout << "Output: " << toString(ans) << std::endl;
}

int main(){
  vector<int> test_1 = {-1,0,1,2,-1,-4};
  runSample(test_1);

  return 0;
}
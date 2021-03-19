#include "solver.hpp"

#include "utils/utils.hpp"

void runSample(vector<int> &nums, int target){
  Solution solver;
  vector<int> res = solver.twoSum(nums, target);

  std::cout << "Input: nums = " << toString(nums) << ", target = " << target << std::endl;
  std::cout << "Output: " << toString(res) << std::endl << std::endl;
}

int main(){
  vector<int> test = {2, 3, 4, 7, 9, 11, 13};
  runSample(test, 6);
  runSample(test, 12);

  return 0;
}
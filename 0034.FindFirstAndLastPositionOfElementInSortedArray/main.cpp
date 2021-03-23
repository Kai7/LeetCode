#include "solver.hpp"
#include "utils/data_structure.hpp"
#include "utils/utils.hpp"

void runSample(vector<int>& nums, int target){
  std::cout << "Input: nums = " << toString(nums) << ", target = " << target << std::endl;
  Solution solver;
  vector<int> ans = solver.searchRange(nums, target);
  std::cout << "Output: " << toString(ans) << std::endl << std::endl;
}

int main(){
  // vector<int> test = {5,7,7,8,8,10};
  vector<int> test = {5,7,7,8,8,8,10};
  // vector<int> test = {5,7,7,8,8,8};
  // vector<int> test = {8,8,8,10};
  // vector<int> test = {8};
  // vector<int> test = {7};
  // vector<int> test = {7,7};
  // vector<int> test = {2,2};
  // vector<int> test = {0,0};

  // runSample(test, 1);
  runSample(test, 8);

  return 0;
}
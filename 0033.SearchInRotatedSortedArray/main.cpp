#include "solver.hpp"
#include "utils/data_structure.hpp"
#include "utils/utils.hpp"

void runSample(vector<int>& nums, int target) {
  std::cout << "Input: nums = " << toString(nums) << ", target = " << target << std::endl;
  Solution solver;
  int ans = solver.search(nums, target);
  std::cout << "Output: " << ans << std::endl << std::endl;
}

int main(){
  // vector<int> test = {4,5,6,7,0,1,2};
  // vector<int> test = {0,1,2,3,4,5,6};
  vector<int> test = {0};
  // vector<int> test = {0,2};
  // vector<int> test = {2,0};

  runSample(test, 0);
  runSample(test, 2);
  runSample(test, 3);
  runSample(test, 4);
  runSample(test, 6);
  runSample(test, 9);

  return 0;
}
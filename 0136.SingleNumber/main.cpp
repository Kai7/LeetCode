#include "solver.hpp"
#include "utils/data_structure.hpp"
#include "utils/utils.hpp"

void runSample(vector<int>& nums) {
  std::cout << "Input: nums = " << toString(nums) << std::endl;
  Solution solver;
  int ans = solver.singleNumber(nums);
  std::cout << "Output: " << ans << std::endl << std::endl;
}

int main(){
  vector<int> test_1 = {2,2,1};
  vector<int> test_2 = {4,1,2,1,2};
  vector<int> test_3 = {1};

  runSample(test_1);
  runSample(test_2);
  runSample(test_3);

  return 0;
}
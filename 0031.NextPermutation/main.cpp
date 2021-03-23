#include "solver.hpp"
#include "utils/data_structure.hpp"
#include "utils/utils.hpp"

void runSample(vector<int>& nums){
  std::cout << "Input: nums = " << toString(nums) << std::endl;
  Solution solver;
  solver.nextPermutation(nums);
  std::cout << "Output: " << toString(nums) << std::endl << std::endl;
}

int main(){
  vector<int> test_1 = {1};
  vector<int> test_2 = {1,2,3};
  vector<int> test_3 = {4,3,2,1};
  vector<int> test_4 = {1,1,5,1};
  vector<int> test_5 = {1,3,5,7,7,6,4};

  runSample(test_1);
  runSample(test_2);
  runSample(test_3);
  runSample(test_4);
  runSample(test_5);

  return 0;
}
#include "solver.hpp"
#include <string>
#include <iterator>
#include <sstream>

std::string vector2str(vector<int> &nums){
  std::stringstream sstr;
  std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(sstr, ", "));
  return sstr.str();
}

void runTwoSum(vector<int> &nums, int target){
  Solution solver;
  vector<int> res = solver.twoSum(nums, target);

  std::cout << "input:\n" 
            << "\tnums: " << vector2str(nums) << std::endl
            << "\ttarget: " << target << std::endl;
  std::cout << "output:\t" << vector2str(res) << std::endl;
}

int main(int argc, char **argv){
  vector<int> test = {2, 3, 4, 7, 9, 11, 13};
  runTwoSum(test, 6);
  runTwoSum(test, 12);

  return 0;
}
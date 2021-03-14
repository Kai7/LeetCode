#include "solver.hpp"

#include <string>
#include <iterator>
#include <sstream>

std::string vector2str(vector<int> &nums){
  std::stringstream sstr;
  std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(sstr, ", "));
  return sstr.str();
}

void runSearchInsertPosition(vector<int> &nums, int target){
  Solution solver;
  std::cout << "input:\n"
            << "\tnums: " << vector2str(nums) << std::endl
            << "\ttarget: " << target << std::endl
            << "output: " << solver.searchInsert(nums, target) << std::endl;
}

int main(int argc, char **argv){
  vector<int> nums = {1, 3, 5, 6};
  int target = 5;
  runSearchInsertPosition(nums, target);
  
  return 0;
}
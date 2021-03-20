#include <vector>
#include <string>
#include <iterator>
#include <sstream>

using std::vector;
using std::string;

std::string toString(vector<int> &nums){
  if (nums.empty()) return "[]";
  std::stringstream sstr;
  sstr << "[" << nums[0];
  for (size_t i = 1; i < nums.size(); i++)
    sstr << "," << nums[i];
  sstr << "]";
  // std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(sstr, ", "));
  return sstr.str();
}

std::string toString(vector<string> &strs){
  if (strs.empty()) return "[]";
  std::stringstream sstr;
  sstr << "[" << strs[0];
  for (size_t i = 1; i < strs.size(); i++)
    sstr << "," << strs[i];
  sstr << "]";
  // std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(sstr, ", "));
  return sstr.str();
}

std::string toString(vector<vector<int>> &nums){
  if (nums.empty()) return "[]";
  std::stringstream sstr;
  sstr << "[" << toString(nums[0]);
  for (size_t i = 1; i < nums.size(); i++)
    sstr << "," << toString(nums[i]);
  sstr << "]";
  return sstr.str();
}
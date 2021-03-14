#include <string>
#include <iterator>
#include <sstream>

std::string vector2str(vector<int> &nums){
  std::stringstream sstr;
  std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(sstr, ", "));
  return sstr.str();
}
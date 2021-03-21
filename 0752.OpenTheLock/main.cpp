#include "solver.hpp"
#include "utils/data_structure.hpp"
#include "utils/utils.hpp"

void runSample(vector<string>& deadends, string target) {
  std::cout << "Input: deadends = " << toString(deadends) << ", target = " << target << std::endl;
  Solution solver;
#if 0
  vector<string> tmp;
  string start_s = "0000";
  if(!solver.getNexStates(start_s, tmp)){
    std::cout << "Error!" << std::endl;
    return;
  }
  std::cout << "next states = " << toString(tmp) << std::endl;
#endif
  int ans = solver.openLock(deadends, target);
  std::cout << "Output: " << ans << std::endl << std::endl;
}

int main(){
  // vector<string> deadends = {"0201","0101","0102","1212","2002"};
  // string target = "0202";
  // vector<string> deadends = {"8888"};
  // string target = "0009";
  vector<string> deadends = {"8887","8889","8878","8898","8788","8988","7888","9888"};
  string target = "8888";

  runSample(deadends, target);

  return 0;
}
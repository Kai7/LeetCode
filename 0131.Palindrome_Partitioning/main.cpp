#include "solver.hpp"
#include "utils/data_structure.hpp"
#include "utils/utils.hpp"

void runSample(string s){
  std::cout << "Input: s = " << addQuotationMark(s) << std::endl;
  Solution solver;
  clock_t tStart = clock();
  vector<vector<string>> ans = solver.partition(s);
  printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
  // bool ans  = solver.isPalindrome(s, 0, s.size() - 1);
  // std::cout << "Output: " << toString(ans) << std::endl << std::endl;
}

int main(){
  // runSample("aa");
  // runSample("aab");
  runSample("aabbcbabcccacc");

  return 0;
}
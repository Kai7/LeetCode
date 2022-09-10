#include "solver.hpp"
#include "utils/data_structure.hpp"
#include "utils/utils.hpp"

void runSample(string num1, string num2){
  std::cout << "Input: num1 = " << addQuotationMark(num1) << ", num2 = " << addQuotationMark(num2) << std::endl;
  Solution solver;
  // string ans = solver.add(num1, num2);
  string ans = solver.multiply(num1, num2);
  std::cout << "Output: " << addQuotationMark(ans) << std::endl << std::endl;

}

int main(){
  // runSample("1", "9");
  runSample("123", "456");
  // runSample("99", "9999");
  // runSample("0", "789");
  // runSample("6", "501");

  return 0;
}
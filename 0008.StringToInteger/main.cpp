#include "solver.hpp"

void runSample(string s){
  Solution sovler;
  int ans = sovler.myAtoi(s);
  std::cout << "Input: s = \"" << s << "\"" << std::endl;
  std::cout << "Output: " << ans << std::endl;

}

int main(){
  runSample("123");
  runSample("  0");
  runSample("  -34 ");
  runSample("2147483647");
  runSample("2147483648");
  runSample("-2147483648");
  runSample("-2147483649");
  runSample("91283472332");
  runSample("-91283472332");
  runSample("1234hello");
  runSample("worlds and 1234 hello");
  runSample("+1234");
  runSample("-+1234");

  return 0;
}
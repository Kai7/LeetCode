#include "solver.hpp"

void checkPalindrome(int x){
  Solution s;
  if (s.isPalindrome(x)){
    std::cout << x << " is Palindrome" << std::endl;
  }else {
    std::cout << x << " is not Palindrome" << std::endl;
  }
}

int main(int argc, char **argv){
  checkPalindrome(-1);
  checkPalindrome(0);
  checkPalindrome(1);
  checkPalindrome(10);
  checkPalindrome(11);
  checkPalindrome(121);
  checkPalindrome(21120);
}
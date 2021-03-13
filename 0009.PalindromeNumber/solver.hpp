#include <iostream>
#include <math.h>

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0) return false;
    if (x == 0 || x == 1) return true;

    float log_x = log10(x);
    int n = (ceil(log_x) == log_x)? ceil(log_x) + 1 : ceil(log_x);
    int *num = new int[n];
    for (int i=0; i<n; i++){
      num[i] = x % 10;
      x /= 10;
    }
    for (int i = 0; i<(n+1)/2; i++){
      if (num[i] != num[n-i-1]){
        return false;
      }
    }

    delete [] num;
    return true;
  }

 /* official version
  bool isPalindrome(int x) {
    if(x < 0 || (x % 10 == 0 && x != 0)) {
      return false;
    }
    int revertedNumber = 0;
    while(x > revertedNumber) {
      revertedNumber = revertedNumber * 10 + x % 10;
      x /= 10;
    }
    return x == revertedNumber || x == revertedNumber/10;
  }
  */
};
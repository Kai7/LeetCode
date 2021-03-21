#include <string>
using std::string;
#include <iostream>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

class Solution {
public:
  int myAtoi(string s) {
    long ans = 0;
    size_t front;
    bool is_positive = true;
    for (size_t i = 0; i < s.size(); i++){
      if (s[i] == ' ') continue;
      if (('0' <= s[i] && s[i] <= '9') || s[i] == '-' || s[i] == '+'){
        front = i;
        break;
      } else {
        return 0;
      }
    }
    if (s[front] == '-' || s[front] == '+') {
      if (s[front] == '-') is_positive = false;
      front += 1;
    }
    for (size_t i = front; i < s.size(); i++){
      if (s[i] < '0' || '9' < s[i]) break;
      ans = 10 * ans + (s[i] - '0');
      if (is_positive && ans > (long)INT32_MAX) return INT32_MAX;
      if (!is_positive && -1 * ans < (long)INT32_MIN) return INT32_MIN;
    }
    if (is_positive) {
      return static_cast<int>(MIN(ans, (long)INT32_MAX));
    } else {
      return static_cast<int>(MAX(-1 * ans, (long)INT32_MIN));
    }
  }
};
#include <string>
using std::string;
#include <iostream>

class Solution {
public:
  int lengthOfLastWord(string s) {
    int rear = s.length() - 1;
    while (rear >= 0 && s[rear] == ' ') rear--;
    if (rear < 0) return 0;
    int front = rear - 1;
    while (front >=0 && s[front] != ' ')  front--;
    return rear - front;
  }
};
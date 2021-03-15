#include <string>
using std::string;
#include <iostream>
#include "stdio.h"
#include <set>
#include <map>

#define MAX(a,b) (((a)>(b))?(a):(b))

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int left = 0;
    size_t length = 0;
    std::map<char, int> history;
    for (int right = 0; right < s.size(); right++){
      if (history.find(s[right]) != history.end() && history[s[right]] >= left){
        length = MAX(length, right - left);
        left = history[s[right]] + 1;
      } 
      history[s[right]] = right;
    }
    length = MAX(length, s.size() - left);

    return static_cast<int>(length);
  }

#if 0
  int lengthOfLongestSubstring(string s) {
    if (s.size() == 1) return 1;
    int front = 0, rear = 0;
    size_t length = 0;
    while (s.size() - front > length && rear != s.size() - 1) {
      std::map<char, int> char_map;
      for (int i = front; i <= rear; i++){
        char_map[s[i]] = i;
      }
      int tmp_front;
      rear += 1;
      while (rear <= s.length() - 1){
        std::map<char, int>::iterator it = char_map.find(s[rear]);
        if (it == char_map.end()){
          char_map[s[rear]] = rear;
          rear += 1;
        } else {
          tmp_front = it->second;
          break;
        }
      }
      length = MAX(length, rear-front);
      front = tmp_front + 1;
    }

    return static_cast<int>(length);
  }
#endif

#if 0
  int lengthOfLongestSubstring(string s) {
    size_t length = 0;
    for (size_t i=0; i < s.size() - length; i++){
      std::set<char> char_set = {s[i]};
      for (size_t j = i+1; j < s.size(); j++){
        std::set<char>::iterator it = char_set.find(s[j]);
        if (it == char_set.end()){
          char_set.insert(s[j]);
        } else{
          break;
        }
      }
      length = MAX(length, char_set.size());
    }
    return static_cast<int>(length);
  }
#endif
};
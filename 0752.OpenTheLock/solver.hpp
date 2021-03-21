#ifndef __LEETCODE_0752__
#define __LEETCODE_0752__
#include "utils/data_structure.hpp"
#include "utils/utils.hpp"
#include <iostream>

class Solution {
public:
  int openLock(vector<string>& deadends, string target) {
    if (target == "0000") return 0;
    set<string> set_deadends;
    for (size_t i = 0; i < deadends.size(); i++){
      set_deadends.insert(deadends[i]);
    }
    if (set_deadends.find("0000") != set_deadends.end()) return -1;
    set<string> set_pass;
    set<string> set_new;
    set_new.insert("0000");
    int ans = 0;
    bool find_target = false;
    while(!set_new.empty()){
      // std::cout << "[" << ans << "] New Set = " << toString(set_new) << std::endl;
      if (set_new.find(target) != set_new.end()){
        find_target = true;
        break;
      }
      set_pass.insert(set_new.begin(), set_new.end());
      set<string> set_new_next;
      for (auto s: set_new){
        vector<string> next_states;
        if(!getNexStates(s, next_states)){
          printf("Error!\n");
          return -1;
        }
        for (size_t i = 0; i < next_states.size(); i++){
          if (set_pass.find(next_states[i]) == set_pass.end()
              && set_deadends.find(next_states[i]) == set_deadends.end())
            set_new_next.insert(next_states[i]);
        }
      }
      set_new = set_new_next;
      ans += 1;
    }
    if (!find_target) return -1;

    return ans;
  }

  bool getNexStates(string &s, vector<string> &next_states) {
    if (!next_states.empty()) return false;
    char numbers[11] = "0123456789";
    for (size_t i = 0; i < s.size(); i++){
      string new_s_1 = s.substr(0,i) + numbers[(s[i]-'0'+1)%10] + s.substr(i+1, s.size()-i-1);
      string new_s_2 = s.substr(0,i) + numbers[(s[i]-'0'+9)%10] + s.substr(i+1, s.size()-i-1);
      next_states.push_back(new_s_1);
      next_states.push_back(new_s_2);
    }
    return true;
  }
};

#endif /* __LEETCODE_0752__ */
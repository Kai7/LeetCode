#include "utils/data_structure.hpp"
#include <iostream>
#include "stdio.h"

class Solution {
public:
  /* Accepted: 38.91, 78,68 */
  vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> ans;
    if (s.length() < words[0].length() * words.size()) return ans;
    unordered_map<string, int> word_idx;
    for (string &w : words){
      if (word_idx.find(w) != word_idx.end()){
        word_idx[w] += 1;
      } else {
        word_idx[w] = 1;
      }
    }
    int word_length = static_cast<int>(words[0].length());
    int last_front = static_cast<int>(s.length()) - word_length * static_cast<int>(words.size());
    for (int init_front = 0; init_front < word_length; init_front ++){
      int front = init_front;
      // printf("front: %d\n", front);
      while(front <= last_front){
        if (word_idx.find(s.substr(front, word_length)) != word_idx.end()){
          unordered_map<string, int> tmp_word_idx;   
          for (string &w : words){
            tmp_word_idx[w] = word_idx[w];
          }
          tmp_word_idx[s.substr(front, word_length)] -= 1;
          for (int i = 1; i <= static_cast<int>(words.size()) - 1; i++){
            if (word_idx.find(s.substr(front + i * word_length, word_length)) != word_idx.end()){
              tmp_word_idx[s.substr(front + i * word_length, word_length)] -= 1;
            } else {
              break;
            }
          }
          bool match = true;
          for (string &w : words){
            // printf("%s : %d\n", w.c_str(), word_idx[w]); 
            if(tmp_word_idx[w] != 0) {
              match = false;
              break;
            }
          }
          if (match){
            ans.push_back(front);
            // printf("%d match\n", front); 
            // tmp_word_idx[s.substr(front, word_length)] += 1;
            while (s.substr(front, word_length) == s.substr(front + static_cast<int>(words.size()) * word_length, word_length)) {
              // printf(" > %s == %s\n", s.substr(front, word_length).c_str(), s.substr(front + static_cast<int>(words.size()) * word_length, word_length).c_str());
              front += word_length;
              ans.push_back(front);
            }
          } 
          if (word_idx.find(s.substr(front + static_cast<int>(words.size()) * word_length, word_length)) == word_idx.end()){
            front += (static_cast<int>(words.size()) + 1) * word_length;
          } else {
            front += word_length;
          }
        } else {
          front += word_length;
        }
      }
    }

    return ans;
  }

#if 0
  /* Accepted: 38.84, 49.90 */
  vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> ans;
    if (s.length() < words[0].length() * words.size()) return ans;
    unordered_map<string, int> word_idx;
    for (string &w : words){
      if (word_idx.find(w) != word_idx.end()){
        word_idx[w] += 1;
      } else {
        word_idx[w] = 1;
      }
    }
    int word_length = static_cast<int>(words[0].length());
    int front = 0;
    int last_front = static_cast<int>(s.length()) - word_length * static_cast<int>(words.size());
    while(front <= last_front){
      if (word_idx.find(s.substr(front, word_length)) != word_idx.end()){
        unordered_map<string, int> tmp_word_idx;   
        for (string &w : words){
          tmp_word_idx[w] = word_idx[w];
        }
        tmp_word_idx[s.substr(front, word_length)] -= 1;
        for (int i = 1; i <= static_cast<int>(words.size()) - 1; i++){
          if (word_idx.find(s.substr(front + i * word_length, word_length)) != word_idx.end()){
            tmp_word_idx[s.substr(front + i * word_length, word_length)] -= 1;
          } else {
            break;
          }
        }
        bool match = true;
        for (string &w : words){
          if(tmp_word_idx[w] != 0) {
            match = false;
            break;
          }
        }
        if (match) ans.push_back(front);
        front += 1;
      } else {
        front += 1;
      }
    }

    return ans;
  }
#endif 

};
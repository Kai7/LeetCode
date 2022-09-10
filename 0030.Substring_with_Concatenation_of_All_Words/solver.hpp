#include "utils/data_structure.hpp"
#include <iostream>
#include "stdio.h"

#define METHOD 0

class Solution {
public:

#if METHOD == 0
  /* review this ... */
  vector<int> findSubstring(string s, vector<string>& words) {
    int w_size = words[0].size(), total_size = words.size() * w_size;
    if (s.size() < total_size) return {};
    unordered_map<string_view, int> w_count;
    for (string& w : words) ++w_count[w];
    vector<int> ret;
    for (int offset = 0; offset < w_size && offset <= s.size() - total_size; ++offset) {
      unordered_map<string_view, int> w_seen;
      int n = 0;
      for (int l = offset, r = l; l <= s.size() - total_size && r <= s.size() - w_size;) {
        string_view tail(s.data() + r, w_size);
        if (!w_count.count(tail)) {
          clear(w_seen, n, l, r, w_size);
          continue;
        }                    
        push(w_seen, n, r, tail);
        if (w_seen[tail] <= w_count[tail]) {
          if (n == words.size()) {
              ret.push_back(l);
              string_view head = string_view(s.data() + l, w_size);
              pop(w_seen, n, l, head);
          }
        } else {
          string_view head;
          do {
              head = string_view(s.data() + l, w_size);
              pop(w_seen, n, l, head);
          } while (head != tail);
        }
      }
    }
    return ret;
  }
  
  void push(unordered_map<string_view, int>& m, int& n, int& r, string_view& w) { ++m[w], ++n, r += w.size(); }

  void pop(unordered_map<string_view, int>& m, int& n, int& l, string_view& w) { --m[w], --n; l += w.size(); }
  
  void clear(unordered_map<string_view, int>& m, int& n, int& l, int& r, int size) { m.clear(), n = 0, l = r += size; }

#elif METHOD == 3
  /* Accepted: 48.22, 77,90 */
  vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> ans;
    if (s.length() < words[0].length() * words.size()) return ans;
    unordered_map<string_view, int> word_idx;
    for (string &w : words){
      if (word_idx.find(w) != word_idx.end()){
        word_idx[w] += 1;
      } else {
        word_idx[w] = 1;
      }
    }
    int word_length = static_cast<int>(words[0].length());
    int words_num = static_cast<int>(words.size());
    int last_front = static_cast<int>(s.length()) - word_length * static_cast<int>(words.size());
    for (int init_front = 0; init_front < word_length; init_front ++){
      int front = init_front;
      while(front <= last_front){
        if (word_idx.find(s.substr(front, word_length)) != word_idx.end()){
          unordered_map<string_view, int> tmp_word_idx = word_idx;   
          tmp_word_idx[s.substr(front, word_length)] -= 1;
          int tmp_counter = 1;
          for (int i = 1; i <= words_num - 1; i++){
            if (tmp_word_idx.find(s.substr(front + i * word_length, word_length)) != tmp_word_idx.end() &&
                tmp_word_idx[s.substr(front + i * word_length, word_length)] > 0) {
              tmp_word_idx[s.substr(front + i * word_length, word_length)] -= 1;
              tmp_counter++;
            } else {
              break;
            }
          }
          if (tmp_counter == words_num){
            ans.push_back(front);
            while (s.substr(front, word_length) == s.substr(front + words_num * word_length, word_length)) {
              front += word_length;
              ans.push_back(front);
            }
          } 
          if (word_idx.find(s.substr(front + words_num * word_length, word_length)) == word_idx.end()){
            front += (words_num + 1) * word_length;
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
#elif METHOD == 2
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
          if (match){
            ans.push_back(front);
            while (s.substr(front, word_length) == s.substr(front + static_cast<int>(words.size()) * word_length, word_length)) {
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

#elif METHOD == 1
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
#else
#error ""
#endif 

};
#include "utils/data_structure.hpp"

class Solution {
public:
  /* 100.00, 50.94 */
  bool isValid(string s) {
    stack<char> st;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
        st.push(s[i]);
      } else {
        if (st.empty()) return false;
        char top = st.top();
        if (top == '(' && s[i] != ')') return false;
        if (top == '[' && s[i] != ']') return false;
        if (top == '{' && s[i] != '}') return false;
        st.pop();
      }
    }
    if (!st.empty()) return false;
    return true;
  }
};
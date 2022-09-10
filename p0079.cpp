#include "utils/data_structure.hpp"

class Solution {
public:
  /* 93.75, 75.19 */
  bool search(vector<vector<char>>& board, string& word, int idx, int i, int j) {
    if (idx == word.size()) return true;
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return false;
    if (board[i][j] != word[idx]) return false;
    idx++;
    char tmp = board[i][j];
    board[i][j] = '\0';
    if (search(board, word, idx, i - 1, j)) return true;
    if (search(board, word, idx, i + 1, j)) return true;
    if (search(board, word, idx, i, j - 1)) return true;
    if (search(board, word, idx, i, j + 1)) return true;
    board[i][j] = tmp;
    return false;
  }
  bool exist(vector<vector<char>>& board, string word) {
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        if (board[i][j] == word[0]) {
          char tmp = board[i][j];
          board[i][j] = '\0';
          if (search(board, word, 1, i - 1, j)) return true;
          if (search(board, word, 1, i + 1, j)) return true;
          if (search(board, word, 1, i, j - 1)) return true;
          if (search(board, word, 1, i, j + 1)) return true;
          board[i][j] = tmp;
        }
      }
    }
    return false; 
  }
};
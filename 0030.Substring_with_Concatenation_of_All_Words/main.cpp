#include "solver.hpp"
#include "utils/data_structure.hpp"
#include "utils/utils.hpp"

void runSample(string s, vector<string>& words){
  std::cout << "Input: s = " << addQuotationMark(s) << ", words = " << toString(words) << std::endl;
  Solution solver;
  vector<int> ans = solver.findSubstring(s, words);
  std::cout << "Output: " << toString(ans) << std::endl << std::endl;
}

int main(){
  string s_1 = "barfoothefoobarman";
  vector<string> words_1 = {"foo", "bar"};
  string s_2 = "wordgoodgoodgoodbestword";
  vector<string> words_2 = {"word","good","best","word"};
  string s_3 = "barfoofoobarthefoobarman";
  vector<string> words_3 = {"bar","foo","the"};
  string s_4 = "abababab";
  vector<string> words_4 = {"a","b","a"};

  runSample(s_1, words_1);
  runSample(s_2, words_2);
  runSample(s_3, words_3);
  runSample(s_4, words_4);    // [0,2,4]

  return 0;
}
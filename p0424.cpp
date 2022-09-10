#include "utils/data_structure.hpp"

#define MAX(a,b) (((a)>(b))?(a):(b))
class Solution {
public:
  /* 94.43, 51.45 */
  int characterReplacement(string s, int k) {
    int ans = 0;
    int start = 0;
    int max_count = 0;
    vector<int> char_counts(26, 0);
    for (int i = 0; i < s.size(); ++i) {
    //   max_count = MAX(max_count, ++char_counts[s[i] - 'A']);
      max_count = std::max(max_count, ++char_counts[s[i] - 'A']);
      while (i - start + 1 - max_count > k) {
        // max_count = MAX(max_count, --char_counts[s[start] - 'A']);
        --char_counts[s[start] - 'A'];
        ++start;
      }
      ans = std::max(ans, i - start + 1);
    }
    return ans;
  }
};

/*
https://www.wongwonggoods.com/python/python_leetcode/leetcode-python-424/
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:

        ans = 0
        window_counter = defaultdict(int)
        max_counter = 0
        start = 0

        for end in range(len(s)):
            # print(start, end, s[start:end+1])
            new_word = s[end]
            window_counter[new_word] += 1
            max_counter = max(max_counter, window_counter[new_word])

            # end - start + 1 = window length (delete max duplicate <= k)
            if (end - start + 1) - max_counter <= k:
                ans = max(ans, end - start + 1)     
            else: # wrong case, move window (first delete then move)
                delete_word = s[start] 
                window_counter[delete_word] -= 1
                start += 1

        return ans
*/
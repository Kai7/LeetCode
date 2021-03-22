#include "solver.hpp"
#include "utils/data_structure.hpp"
#include "utils/utils.hpp"

ListNode* runSample(ListNode* head) {
  std::cout << "Input: head = " << toString(head) << std::endl;
  Solution solver;
  ListNode *ans = solver.swapPairs(head);
  std::cout << "Output: " << toString(ans) << std::endl << std::endl;
  return ans;
}

int main() {
  // vector<int> test = {1,2,3,4};
  // vector<int> test = {};
  // vector<int> test = {1};
  vector<int> test = {1,2,3,4,5,6,7,8,9};

  ListNode *head = createLinkedList(test);
  head = runSample(head);
  deleteLinkedList(head);

  return 0;
}
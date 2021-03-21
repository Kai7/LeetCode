#include "solver.hpp"
#include "utils/data_structure.hpp"
#include "utils/utils.hpp"

ListNode* runSample(ListNode* l1, ListNode* l2) {
  Solution solver;
  std::cout << "Input: l1 = " << toString(l1) << ", l2 = " << toString(l2) << std::endl;
  ListNode *ans = solver.mergeTwoLists(l1, l2);
  std::cout << "Output: " << toString(ans) << std::endl << std::endl;

  return ans;
}

int main(){
  // vector<int> d1 = {1,2,4};
  // vector<int> d2 = {1,3,4};
  vector<int> d1 = {2};
  vector<int> d2 = {1};

  ListNode *l1 = createLinkedList(d1);
  ListNode *l2 = createLinkedList(d2);
  ListNode *head = runSample(l1, l2);

  deleteLinkedList(head);

  return 0;
}
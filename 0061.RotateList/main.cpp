#include "solver.hpp"
#include "utils/data_structure.hpp"
#include "utils/utils.hpp"

ListNode* runSample(ListNode* head, int k){
  std::cout << "Input: head = " << toString(head) << ", k = " << k << std::endl;
  Solution solver;
  ListNode *ans = solver.rotateRight(head, k);
  std::cout << "Output: " << toString(ans) << std::endl << std::endl;
  return ans;
}

int main() {
  vector<int> data = {1,2,3,4,5,6};
  ListNode *head = createLinkedList(data);

  // head = runSample(head, 0);
  head = runSample(head, 1);
  // head = runSample(head, 3);
  // head = runSample(head, 5);
  // head = runSample(head, 6);

  deleteLinkedList(head);
  return 0;
}
#include "solver.hpp"
#include "utils/data_structure.hpp"
#include "utils/utils.hpp"

void runSample(ListNode *head){
  std::cout << "Input: head = " << toString(head) << std::endl;
  Solution solver;
  bool ans = solver.hasCycle(head);
  std::cout << "Output: " << toString(ans) << std::endl;
}

int main(){
  vector<int> data = createSimpleVector(1);

  ListNode* head = createLinkedList(data);
  ListNode* rear = getRearPtr(head);
  rear->next = head;
  // rear->next = head->next->next;

  runSample(head);
  deleteLinkedList(head);
  return 0;
}
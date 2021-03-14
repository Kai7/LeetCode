#include "solver.hpp"

#include <string>
#include <sstream>

std::string linkedlist2str(ListNode *r){
  std::stringstream sstr("");
  while (r != nullptr) {
    sstr << r->val;
    r = r->next;
  }
  return sstr.str();
}

ListNode* createLinkedList(int x){
  ListNode *r = new ListNode(x);
  ListNode *front = r;
  while (front->val >= 10) {
    front->next = new ListNode(front->val / 10);
    front->val %= 10;
    front = front->next;
  }
  return reverseListNode(r);
}

void runAddTwoNumbers(ListNode* l1, ListNode* l2){
  Solution solver;
  std::cout << "input:\n"
            << "\tl1: " << linkedlist2str(l1) << std::endl
            << "\tl2: " << linkedlist2str(l2) << std::endl;
  ListNode *ans = solver.addTwoNumbers(l1, l2);
  std::cout << "output: " << linkedlist2str(ans) << std::endl;
}

int main(int argc, char **argv){
  // ListNode *l1 = createLinkedList(243);
  // ListNode *l2 = createLinkedList(564);
  ListNode *l1 = createLinkedList(0);
  ListNode *l2 = createLinkedList(0);
  // ListNode *l1 = createLinkedList(9999999);
  // ListNode *l2 = createLinkedList(9999);
  runAddTwoNumbers(l1, l2);

  return 0;
}
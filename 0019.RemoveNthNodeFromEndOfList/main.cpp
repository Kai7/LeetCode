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

ListNode* reverseListNode(ListNode* r){
  if (r == nullptr) return nullptr;
  ListNode *p = nullptr;
  ListNode *c = r;
  ListNode *n = c->next;
  c->next = nullptr;
  while (n != nullptr) {
    p = c;
    c = n;
    n = n->next;
    c->next = p;
  }
  return c; 
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

void deleteLinkedList(ListNode *head){
  if (head == nullptr) return;
  ListNode *next_ptr = head->next;
  delete head;
  deleteLinkedList(next_ptr);
}

ListNode* runSample(ListNode* head, int n){
  Solution solver;
  std::cout << "Input: head = " << linkedlist2str(head) << ", n = " << n << std::endl;
  ListNode *ans = solver.removeNthFromEnd(head, n);
  std::cout << "Output: " << linkedlist2str(ans) << std::endl << std::endl;

  return ans;
}

int main(){
  ListNode *test_1 = createLinkedList(12345);
  ListNode *test_2 = createLinkedList(1234567);
  ListNode *test_3 = createLinkedList(1234567);

  test_1 = runSample(test_1, 5);
  test_2 = runSample(test_2, 1);
  test_3 = runSample(test_3, 7);

  deleteLinkedList(test_1);
  deleteLinkedList(test_2);
  deleteLinkedList(test_3);

  return 0;
}
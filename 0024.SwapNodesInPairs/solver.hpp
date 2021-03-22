#include "utils/data_structure.hpp"
#include <iostream>

class Solution {
public:
  ListNode* swapPairs(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode *ptr1 = head, *ptr2 = head->next;
    ptr1->next = ptr2->next;
    ptr2->next = ptr1;
    head = ptr2;
    ListNode *done = ptr1;
    while(done->next != nullptr && done->next->next != nullptr) {
      ptr1 = done->next;
      ptr2 = done->next->next;
      done->next = ptr2;
      ptr1->next = ptr2->next;
      ptr2->next = ptr1;
      done = ptr1;
    }
    return head;
  }
};
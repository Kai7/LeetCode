#include "utils/data_structure.hpp"

class Solution {
public:
  /* 73.40, 57.78 */
  bool hasCycle(ListNode *head) {
    if (head == nullptr) return false;
    ListNode *p1 = head;
    ListNode *p2 = head->next;
    while (p2 != nullptr) {
      if (p2 == p1) return true;
      p2 = p2->next;
      if (p2 == nullptr) return false;
      p2 = p2->next;
      p1 = p1->next;
    }
    return false;
  }
};
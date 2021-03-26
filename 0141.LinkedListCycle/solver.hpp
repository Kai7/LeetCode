#include "utils/data_structure.hpp"
#include <iostream>

class Solution {
public:
  /* Accepted: 57.93, 49.83 */
  bool hasCycle(ListNode *head) {
    if (head == nullptr) return false;
    ListNode *p1 = head; 
    ListNode *p2 = head->next;
    while (p2 != nullptr){
      if (p1 == p2) return true;
      if (p2->next == nullptr) return false;
      p1 = p1->next;
      p2 = p2->next->next;
    }
    return false;
  }
};
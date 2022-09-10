#include "utils/data_structure.hpp"
class Solution {
public:
  /* 58.86, 96.44 */
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *p = nullptr;
    ListNode *q = head;
    ListNode *t = head;
    for (int i = 1; i < n; i++) {
      t = t->next;
    }
    while (t->next != nullptr) {
      p = q;
      q = q->next;
      t = t->next;
    }
    if (p == nullptr) return head->next;
    p->next = q->next;
    return head;
  }
};
#include "utils/data_structure.hpp"

class Solution {
public:
  /* 35.64, 37.01 */
  ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr) return nullptr;
    ListNode *p = head;
    while (p != nullptr) {
      ListNode *q = p->next;
      while (q != nullptr && q->val == p->val) q = q->next;
      ListNode *r = p->next;
      p->next = q;
      while (r != q) {
        ListNode *t = r;
        r = r->next;
        delete t;
      }
      p = q;
    }
    return head;
  }
};
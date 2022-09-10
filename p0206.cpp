#include "utils/data_structure.hpp"

#define METHOD 0

class Solution {
public:
#if METHOD == 0
  /* 54.63, 42.11 */
  ListNode* reverseList(ListNode* head) {
    ListNode *t = nullptr;
    ListNode *p = nullptr;
    ListNode *q = head;
    while (q != nullptr) {
      t = q->next;
      q->next = p;
      p = q;
      q = t;
    }
    return p;
  }
#elif METHOD == 1
  /* 5.84, 79.70 */
  ListNode* reverseList(ListNode* head) {
    if (head == nullptr) return head;
    if (head->next == nullptr) return head;
    ListNode *p = head;
    ListNode *q = head->next;
    head->next = nullptr;
    ListNode *r;
    while (q != nullptr) {
      r = q->next;
      q->next = p;
      p = q;
      q = r;
    }
    return p;
  }
#else
#endif
};
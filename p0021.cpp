#include "utils/data_structure.hpp"

#define MIN(a,b) (((a)<(b)):(a)?(b))
class Solution {
public:
  /* 63.91, 81.48 */
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr) return list2;
    if (list2 == nullptr) return list1;
    ListNode *h1 = list1;
    ListNode *h2 = list2;
    ListNode *ans, *ans_end;
    if (h1->val <= h2->val) {
      ans = h1;
      h1 = h1->next;
    } else {
      ans = h2;
      h2 = h2->next;
    }
    ans_end = ans;
    while (h1 != nullptr && h2 != nullptr) {
      ListNode **p = (h1->val <= h2->val) ? &h1 : &h2;
      ListNode *q = *p;
      while (q->next != nullptr && q->next->val == (*p)->val) q = q->next;
      ans_end->next = *p;
      ans_end = q;
      (*p) = ans_end->next;
    }
    if (h1 != nullptr) {
      ans_end->next = h1;
    }
    if (h2 != nullptr) {
      ans_end->next = h2;
    }
    return ans;
  }
};
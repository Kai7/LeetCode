#include "utils/data_structure.hpp"

#define METHOD 0
class Solution {
public:
#if METHOD == 0
  /* 65.86, 50.05 */
  void reorderList(ListNode* head) {
    if (head == nullptr || head->next == nullptr || head->next->next == nullptr) return;
    ListNode* p1 = head->next;
    ListNode* p2 = head->next->next;
    while (p2->next != nullptr && p2->next->next != nullptr) {
      p1 = p1->next;
      p2 = p2->next->next;
    }
    ListNode *cur = p1->next;
    p1->next = nullptr;
    ListNode *pre = nullptr;
    while (cur != nullptr) {
      ListNode *next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }
    p1 = head;
    p2 = pre;
    while (p1 != nullptr && p2 != nullptr) {
      ListNode *tmp = p2->next;
      p2->next = p1->next;
      p1->next = p2;
      p1 = p2->next;
      p2 = tmp;
    }
  }
#elif METHOD == 1
  /* 52.94, 12.65 */
  void reorderList(ListNode* head) {
    if (head == nullptr) return;
    vector<ListNode*> buf;
    ListNode *p = head;
    while (p != nullptr) {
      buf.push_back(p);
      p = p->next;
    }
    int i = 0, j = buf.size() - 1;
    while (i < j) {
      buf[i]->next = buf[j];
      i++;
      if (i == j) break;
      buf[j]->next = buf[i];
      j--;
    }
    buf[i]->next = nullptr;
  }
#else
#endif
};
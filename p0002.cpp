#include "utils/data_structure.hpp"

class Solution {
public:
  /* 84.87, 82.23 */
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;
    ListNode *p1 = l1;
    ListNode *p2 = l2;
    ListNode *root = new ListNode();
    ListNode *tmp = root;
    int carry = 0;
    while (carry != 0 || p1 != nullptr || p2 != nullptr) {
      int v1 = (p1 == nullptr) ? 0 : p1->val;
      int v2 = (p2 == nullptr) ? 0 : p2->val;
      carry += v1 + v2;
      tmp->next = new ListNode(carry % 10);
      carry /= 10;
      tmp = tmp->next;

      if (p1) p1 = p1->next;
      if (p2) p2 = p1->next;
    }
    return root->next; 
  }
};
#include <assert.h>
#include <stdio.h>
#include <iostream>
/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#define GET_VAL(node) ((node == nullptr) ? 0 : node->val)
#define GET_NEXT(node) ((node == nullptr) ? nullptr : node->next)

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

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int x1 = GET_VAL(l1);
    int x2 = GET_VAL(l2);
    ListNode *ans = new ListNode(x1 + x2);
    ListNode *add_ptr = ans;
    int overflow = add_ptr->val / 10;
    add_ptr->val %= 10;
    l1 = GET_NEXT(l1);
    l2 = GET_NEXT(l2);
    while (l1 != nullptr || l2 != nullptr || overflow != 0) {
      x1 = GET_VAL(l1);
      x2 = GET_VAL(l2);
      add_ptr->next = new ListNode(x1 + x2 + overflow);
      add_ptr = add_ptr->next;
      overflow = add_ptr->val / 10;
      add_ptr->val %= 10;
      l1 = GET_NEXT(l1);
      l2 = GET_NEXT(l2);
    }
    return ans;
  }

#if 0
/*  Misunderstanding Problem...*/
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *l1_rev = reverseListNode(l1);
    ListNode *l2_rev = reverseListNode(l2);
    int x1 = GET_VAL(l1_rev);
    int x2 = GET_VAL(l2_rev);
    ListNode *ans = new ListNode(x1 + x2);
    ListNode *add_ptr = ans;
    int overflow = add_ptr->val / 10;
    add_ptr->val %= 10;
    l1_rev = GET_NEXT(l1_rev);
    l2_rev = GET_NEXT(l2_rev);
    while (l1_rev != nullptr || l2_rev != nullptr || overflow != 0) {
      x1 = GET_VAL(l1_rev);
      x2 = GET_VAL(l2_rev);
      add_ptr->next = new ListNode(x1 + x2 + overflow);
      add_ptr = add_ptr->next;
      overflow = add_ptr->val / 10;
      add_ptr->val %= 10;
      l1_rev = GET_NEXT(l1_rev);
      l2_rev = GET_NEXT(l2_rev);
    }
    return reverseListNode(ans);
  }
#endif
};
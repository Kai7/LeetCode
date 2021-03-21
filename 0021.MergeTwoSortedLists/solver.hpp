#ifndef __LEETCODE_0021__
#define __LEETCODE_0021__
#include "utils/data_structure.hpp"
#include "stdio.h"
#include <iostream>

class Solution {
public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;
    ListNode *ptr_1 = l1, *ptr_2 = l2;
    ListNode *ptr_done = nullptr;
    ListNode *ans = nullptr;
    if (ptr_2->val < ptr_1->val){
      ListNode *ptr_tmp = ptr_2->next;
      ptr_2->next = ptr_1;
      ptr_done = ptr_2;
      ptr_2 = ptr_tmp;
    } else {
      ptr_done = ptr_1;
      ptr_1 = ptr_1->next;
    }
    ans = ptr_done;
    while (ptr_1 != nullptr && ptr_2 != nullptr) {
      if (ptr_2->val < ptr_1->val){
        ptr_done->next = ptr_2;
        ListNode *ptr_tmp = ptr_2->next;
        ptr_2->next = ptr_1;
        ptr_2 = ptr_tmp;
      } else {
        ptr_1 = ptr_1->next;
      }
      ptr_done = ptr_done->next;
    }
    if(ptr_2 != nullptr){
      ptr_done->next = ptr_2;
    }
    return ans;
  }
};

#endif /* __LEETCODE_0021_ */
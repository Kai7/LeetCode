#include "utils/data_structure.hpp"
#include <iostream>
#include "stdio.h"

class Solution {
public:
  /* Accepted: 59.45, 76.56 */
  ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr) return head;
    int length = 1;
    ListNode *rear = head;
    while (rear->next != nullptr){
      length++;
      rear = rear->next;
    }
    k %= length;
    if (k == 0) return head;
    ListNode *pivot = head;
    for (int i = 1; i < length - k; i++) pivot = pivot->next;
    ListNode *new_head = pivot->next;
    pivot->next = nullptr;
    rear->next = head;
    return new_head;
  }
};
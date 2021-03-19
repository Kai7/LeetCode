#include <vector>
using std::vector;
#include <iostream>

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    vector<ListNode*> ptr_buffer;
    ListNode *p = head;
    while (p != nullptr) {
      ptr_buffer.push_back(p);
      p = p->next;
    }
    int buffer_size = static_cast<int>(ptr_buffer.size());
    if (ptr_buffer.size() == 1) {
      delete head;
      return nullptr;
    }
    if (n == buffer_size) {
      delete head;
      return ptr_buffer[1];
    }
    p = ptr_buffer[buffer_size - n - 1];
    ListNode *q = ptr_buffer[buffer_size - n];
    ListNode *r = q->next;
    p->next = r;
    delete q;

    return head; 
  }
};
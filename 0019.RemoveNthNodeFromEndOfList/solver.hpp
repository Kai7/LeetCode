#include <vector>
using std::vector;
#include <iostream>

#define METHOD 0

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
#if METHOD == 0
  /* 74.25, 32.12 */
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == nullptr) return nullptr;
    ListNode *p = head;
    int node_num = 1;
    while (p->next != nullptr){
      p = p->next;
      node_num++;
    }
    if (node_num == n) {
      p = head->next;
      delete head;
      return p;
    }
    p = head;
    for (int i = 1; i < node_num - n; i++) {
      p = p->next;
    }
    ListNode *q = p;
    p = p->next;
    q->next = p->next;
    delete p;

    return head;
  }

#elif METHOD == 2
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    /* 21.80, 74.62 */
    if (head == nullptr) return nullptr;
    ListNode *p0, *p1, *p2, *q;
    q = head;
    for (int i = 1; i < n; i++) {
      q = q->next;
    }
    p0 = nullptr;
    p1 = head;
    p2 = p1->next;
    while(q->next != nullptr) {
      p0 = p1;
      p1 = p2;
      p2 = p2->next;
      q = q->next;
    }
    if (p1 == head) {
      delete p1;
      return p2;
    }
    delete p1;
    p0->next = p2;
    return head;
  }

#elif METHOD == 1
  /* 74.19, 0.00 */
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
#else
#endif
};
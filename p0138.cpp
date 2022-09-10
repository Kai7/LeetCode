// #include "utils/data_structure.hpp"
#include <stdlib.h>
#include <unordered_map>

class Node {
public:
  int val;
  Node* next;
  Node* random;
  
  Node(int _val) {
      val = _val;
      next = NULL;
      random = NULL;
  }
};

class Solution {
public:
  /* 16.30, 60.64 */
  Node* copyRandomList(Node* head) {
    if (!head) return NULL;
    std::unordered_map<Node*, Node*> m;
    Node *ans = new Node(0);
    Node *p = ans;
    Node *q = head;
    while (q) {
      if (m.find(q) == m.end()) {
        m[q] = new Node(q->val);
      }
      p->next = m[q];
      p = p->next;
      if (q->random) {
        if (m.find(q->random) == m.end()) {
          m[q->random] = new Node(q->random->val);
        }
        p->random = m[q->random];
      }
      q = q->next;
    }
    return ans->next;
  }
};
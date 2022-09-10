#include "utils/data_structure.hpp"

#define METHOD 0

class Solution {
public:
#if METHOD == 0
  /* 92.45, 83.40 */
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    auto cmp = [](ListNode*& a, ListNode*& b) -> bool {
      return a->val > b->val;
    };
    std::priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
    for (ListNode*& node: lists) {
      if (node != nullptr) pq.push(node);
    }
    ListNode dummy(-1);
    ListNode *cur = &dummy;
    while (!pq.empty()) {
      ListNode* tmp = pq.top();
      pq.pop();
      cur->next = tmp;
      cur = cur->next;
      if (tmp->next != nullptr) pq.push(tmp->next);
    }
    return dummy.next;
  }
#elif METHOD == 1
  /* 6.06, 83.40 */
  int findMinHead(vector<ListNode*>& lists) {
    int idx = -1;
    int value = INT32_MAX;
    for (int i = 0; i < lists.size(); ++i) {
      if (lists[i] == nullptr) continue;
      if (lists[i]->val < value) {
        idx = i;
        value = lists[i]->val;
      }
    }
    return idx;
  }
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.size() == 0) return nullptr;
    vector<ListNode*> heads = vector<ListNode*>(lists.begin(), lists.end());
    int idx = findMinHead(heads);
    if (idx == -1) return nullptr;
    ListNode* p = heads[idx];
    ListNode* q = p;
    while (q->next != nullptr && q->next->val == p->val) q = q->next;
    ListNode* ans = p;
    ListNode* ans_end = q;
    heads[idx] = q->next;

    idx = findMinHead(heads);
    while (idx != -1) {
      p = heads[idx];
      q = p;
      while (q->next != nullptr && q->next->val == p->val) q = q->next;
      ans_end->next = p;
      ans_end = q;
      heads[idx] = q->next;
      idx = findMinHead(heads);
    }
    return ans;
  }
#else
#endif
};
#ifndef __LEETCODE_DATA_STRUCTURE__
#define __LEETCODE_DATA_STRUCTURE__
#include <string>
#include <vector>
#include <set>
#include <map>

using std::string;
using std::vector;
using std::set;
using std::map;

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#endif /* __LEETCODE_DATA_STRUCTURE__ */
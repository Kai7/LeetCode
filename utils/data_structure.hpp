#ifndef __LEETCODE_DATA_STRUCTURE__
#define __LEETCODE_DATA_STRUCTURE__
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>

using std::string;
using std::vector;
using std::set;
using std::map;
using std::unordered_map;
using std::pair;
using std::queue;

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#endif /* __LEETCODE_DATA_STRUCTURE__ */
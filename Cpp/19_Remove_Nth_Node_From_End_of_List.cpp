/*
https://leetcode.com/problems/remove-nth-node-from-end-of-list/

Given the head of a linked list, remove the nth node from the end of the list and return its head.

Follow up: Could you do this in one pass?

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz

ref:
https://leetcode.com/problems/remove-nth-node-from-end-of-list/solution/
https://www.cnblogs.com/grandyang/p/4606920.html

*/
#include <bits/stdc++.h>

#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *pre = head, *cur = head;
        for (int i = 0; i < n; i++) {
            cur = cur->next;
        }
        if (!cur) return pre->next;
        while (cur->next) {
            pre = pre->next;
            cur = cur->next;
        }
        // 避免 memory leak
        ListNode* tmp = pre->next;
        pre->next = pre->next->next;
        tmp->next = NULL;
        delete tmp;
        return head;
    }
};
class Solution_dummyNode {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(-1), *fast = dummy, *slow = dummy;
        dummy->next = head;
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};
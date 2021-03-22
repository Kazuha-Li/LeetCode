/*
https://leetcode.com/problems/middle-of-the-linked-list/

Given a non-empty, singly linked list with head node head, return a middle node of linked list.

If there are two middle nodes, return the second middle node.

Example 1:

Input: [1,2,3,4,5]
Output: Node 3 from this list (Serialization: [3,4,5])
The returned node has value 3.  (The judge's serialization of this node is [3,4,5]).
Note that we returned a ListNode object ans, such that:
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, and ans.next.next.next = NULL.
Example 2:

Input: [1,2,3,4,5,6]
Output: Node 4 from this list (Serialization: [4,5,6])
Since the list has two middle nodes with values 3 and 4, we return the second one.
 

Note:

The number of nodes in the given list will be between 1 and 100.

ref:
https://leetcode.com/problems/middle-of-the-linked-list/solution/

*/

#include <bits/stdc++.h>

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution_count_length {
   public:
    // Approach 1: 計算長度
    // Time = O(n)
    // Space = O(1)
    ListNode* middleNode(ListNode* head) {
        int length = 0;
        ListNode* t = head;
        while (t) {
            length++;
            t = t->next;
        }
        t = head;
        length /= 2;
        while (length > 0) {
            length--;
            t = t->next;
        }
        return t;
    }
};
class Solution_array {
   public:
    // Approach 2: use array
    // Time = O(n)
    // Space = O(n)
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> res{head};
        while (res.back()->next) {
            res.push_back(res.back()->next);
        }
        return res[res.size() / 2];
    }
};
class Solution_one_pass {
   public:
    // 利用fast、slow兩個指針
    // fast 每次比 slow 多走一格
    // Time = O(n)
    // Space = O(1)
    ListNode* middleNode(ListNode* head) {
        ListNode *fast = head, *slow = head;
        // 當List長度為偶數如果要第一個mid則條件為
        // while(fast->next && fast->next->next)
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};

int main() {
    return 0;
}
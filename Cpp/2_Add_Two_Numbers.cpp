/* 
https://leetcode.com/problems/add-two-numbers/

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.

ref:
https://leetcode.com/problems/add-two-numbers/solution/
https://www.cnblogs.com/grandyang/p/4129891.html

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
    // 注意 l1,l2 可能會不等長
    // Time = O(max(m,n)) m,n 分別代表 l1,l2 的長度
    // Space = O(max(m,n))
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *newHead = new ListNode(0), *t = newHead;
        int carry = 0;
        while (l1 || l2) {
            int l1_val = l1 ? l1->val : 0;
            int l2_val = l2 ? l2->val : 0;
            int curSum = l1_val + l2_val + carry;
            carry = curSum / 10;
            curSum = curSum % 10;
            t->next = new ListNode(curSum);  // 注意新增ListNode的寫法
            t = t->next;
            if (l1) l1 = l1->next;  // 如果 l1 != NULL 才執行
            if (l2) l2 = l2->next;
        }
        // 處理最後的carry
        if (carry) t->next = new ListNode(1);
        return newHead->next;
    }
};

int main(int argc, char const* argv[]) {
    int tmp = 12;
    cout << tmp << endl;
    int m = tmp / 10;
    cout << m << endl;
    tmp %= 10;
    cout << tmp << endl;
    return 0;
}

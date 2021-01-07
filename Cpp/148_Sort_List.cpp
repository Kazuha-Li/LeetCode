/*
https://leetcode.com/problems/sort-list/

Given the head of a linked list, return the list after sorting it in ascending order.

Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)? 

Example 1:


Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105

ref:
https://leetcode.com/problems/sort-list/solution/
https://www.cnblogs.com/grandyang/p/4249905.html
*/

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

class Solution {
   public:
    // Bottom Up Merge Sort 見 ref:
    // Bottom Up 的方法可以讓 Space = O(1)

    // Top Down Merge Sort
    // Space = O(logn) , where n is the number of nodes in linked list.
    // Since the problem is recursive, we need additional space to store the recursive call stack.
    // The maximum depth of the recursion tree is (logn)
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        // devide
        // 利用快慢指針找出Linklist的中點
        ListNode *fast = head, *slow = head, *pre = head;
        while (fast && fast->next) {
            pre = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        pre->next = NULL;
        // 合併
        return merge(sortList(head), sortList(slow));
    }
    ListNode* merge(ListNode* l_head, ListNode* r_head) {
        // ListNode* dummyHead = new ListNode(0);
        // ListNode* tmp = dummyHead;
        // 這樣的寫法跑起來會比上面兩行還要快
        ListNode dummyHead(0);
        ListNode* tmp = &dummyHead;
        while (l_head && r_head) {
            if (l_head->val < r_head->val) {
                tmp->next = l_head;
                l_head = l_head->next;
            } else {
                tmp->next = r_head;
                r_head = r_head->next;
            }
            tmp = tmp->next;
        }
        // 如果最後還有剩
        tmp->next = (l_head) ? l_head : r_head;
        return dummyHead.next;
    }
};

int main() {
    return 0;
}
/*
https://leetcode.com/problems/merge-two-sorted-lists/

Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.

Example 1:


Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: l1 = [], l2 = []
Output: []
Example 3:

Input: l1 = [], l2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both l1 and l2 are sorted in non-decreasing order.

ref:
https://www.cnblogs.com/grandyang/p/4086297.html
https://leetcode.com/problems/merge-two-sorted-lists/discuss/9714/14-line-clean-C%2B%2B-Solution
https://ithelp.ithome.com.tw/articles/10213265
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
    // 遞迴寫法
    // Time = O(n)
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
    /*
    // Time = O(n) n代表 l1 及 l2 的長度總和
    // Space = O(1) 
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode(0), *cur = ans;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        // if(l1 != NULL) cur->next = l1;
        // else cur->next = l2;
        // 意思與上面兩行相同
        cur->next = (l1) ? l1 : l2;
        return ans->next;
    }
    */

    /*
    // Time = O(n)
    // Space = O(1)
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *cur, *cur_brfore, *t;
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        if (l1->val <= l2->val) {
            cur_brfore = l1;
            cur = l1->next;
            while (cur != NULL && l2 != NULL) {
                if (cur->val > l2->val) {
                    t = l2->next;
                    l2->next = cur;
                    cur_brfore->next = l2;
                    l2 = t;
                } else {
                    cur = cur->next;
                }
                cur_brfore = cur_brfore->next;
            }
            if (l2) cur_brfore->next = l2;
            return l1;
        } else {
            cur_brfore = l2;
            cur = l2->next;
            while (cur && l1) {
                if (cur->val > l1->val) {
                    t = l1->next;
                    l1->next = cur;
                    cur_brfore->next = l1;
                    l1 = t;
                } else {
                    cur = cur->next;
                }
                cur_brfore = cur_brfore->next;
            }
            if (l1) cur_brfore->next = l1;
            return l2;
        }

        return NULL;
    }
    */
};
int main() {
    return 0;
}
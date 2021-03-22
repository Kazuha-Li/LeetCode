/*
https://leetcode.com/problems/reverse-linked-list/

Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?

ref:
https://www.cnblogs.com/grandyang/p/4478820.html
http://glj8989332.blogspot.com/2019/08/leetcode-206-reverse-linked-list.html

*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution_recursive {
   public:
    // Approach 1: recursively
    // Time = O(n)
    // Space = O(n)

    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
};
class Solution_iterative {
   public:
    // iteratively
    // Time = O(n)
    // Space = O(1)
    ListNode* reverseList(ListNode* head) {
        ListNode *newHead = NULL, *t;
        while (head) {
            // 儲存 head 指向的下一個元素
            t = head->next;
            head->next = newHead;
            newHead = head;
            head = t;
        }
        return newHead;
    }
};

int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}

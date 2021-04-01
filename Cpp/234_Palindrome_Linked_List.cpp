/* 
https://leetcode.com/problems/palindrome-linked-list/

Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?

ref:
https://www.cnblogs.com/grandyang/p/4635425.html

*/

#include <bits/stdc++.h>

#include <iostream>
#include <stack>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution_reverse_second_half {
   public:
    // 解法二
    // 先找出 LinkedList 的中點，注意奇數偶數！
    // 將後半段 reverse 之後進行比對
    // Time = O(n)
    // Space = O(1)
    bool isPalindrome(ListNode *head) {
        if (!head || !head->next) return true;
        ListNode *fast = head, *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast) slow = slow->next;  // length is odd
        ListNode *dummyHead = NULL;
        ListNode *t;
        // reverse 後半段的 LinkedList
        while (slow) {
            t = slow->next;
            slow->next = dummyHead;
            dummyHead = slow;
            slow = t;
        }
        while (dummyHead) {
            if (dummyHead->val != head->val) return false;
            dummyHead = dummyHead->next;
            head = head->next;
        }
        return true;
    }
};
class Solution_reverse_second_half_II {
   public:
    // 方法同上，但是不需要判斷List 是 odd or even
    bool isPalindrome(ListNode *head) {
        if (!head) return true;
        ListNode *fast = head, *slow = head;
        // 這裡while裡面的條件如果List長度是odd會停在中間
        // even的話會停在兩個中間較前面的那一個
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // reverse
        fast = slow->next;
        ListNode *newHead = NULL, *t;
        while (fast) {
            t = fast->next;
            fast->next = newHead;
            newHead = fast;
            fast = t;
        }
        t = head;
        while (newHead) {
            if (t->val != newHead->val) return false;
            newHead = newHead->next;
            t = t->next;
        }
        return true;
    }
};
class Solution_stack {
   public:
    // 解法一
    // 利用 stack 以及快慢指針，將中間以前的元素依序push進去stack
    // 後半段每個與stack的top元素比較
    // Time = O(n)
    // Space = O(n)
    bool isPalindrome(ListNode *head) {
        if (!head || !head->next) return true;
        ListNode *fast = head, *slow = head;
        stack<int> st;
        while (fast && fast->next) {
            st.push(slow->val);
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast) slow = slow->next;  // length is odd
        while (slow) {
            if (slow->val != st.top()) return false;
            st.pop();
            slow = slow->next;
        }
        return true;
    }
};

class Solution_stack_II {
   public:
    // 同上，不同之處在於push進stack的是後半段，不用判斷List是 odd 還是 even
    bool isPalindrome(ListNode *head) {
        if (!head) return true;
        ListNode *fast = head, *slow = head;
        // 這裡while裡面的條件如果List長度是odd會停在中間
        // even的話會停在兩個中間較前面的那一個
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        stack<ListNode *> st;
        while (slow->next) {
            st.push(slow->next);
            slow = slow->next;
        }
        fast = head;
        while (!st.empty()) {
            if (fast->val != st.top()->val) return false;
            st.pop();
            fast = fast->next;
        }
        return true;
    }
};

class Solution_vector {
   public:
    // output到vector然後複製一份之後reverse
    // Time = O(n)
    // Spce = O(n)
    bool isPalindrome(ListNode *head) {
        if (!head) return true;
        ListNode *t = head;
        vector<int> res;
        while (t) {
            res.push_back(t->val);
            t = t->next;
        }
        vector<int> revRes(res.begin(), res.end());
        reverse(revRes.begin(), revRes.end());

        for (int i = 0; i < res.size(); i++) {
            if (res[i] != revRes[i]) return false;
        }
        return true;
    }
};

int main(int argc, char const *argv[]) {
    return 0;
}

/*
https://leetcode.com/problems/min-stack/

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 

Constraints:

Methods pop, top and getMin operations will always be called on non-empty stacks.

ref:
http://alrightchiu.github.io/SecondRound/stack-neng-gou-zai-o1qu-de-zui-xiao-zhi-de-minstack.html
https://www.cnblogs.com/grandyang/p/4091064.html

*/

#include <iostream>
#include <stack>
using namespace std;
// 利用兩個Stack來實作，其中一個存放data 另一個紀錄 minimum
class MinStack {
   public:
    /** initialize your data structure here. */
    MinStack() {
    }

    void push(int x) {
        dataStack.push(x);
        if (minmumStack.empty() || x < minmumStack.top())
            minmumStack.push(x);
        else
            minmumStack.push(minmumStack.top());  //把minimumStack頂端元素再 push 一個進去
    }

    void pop() {
        // 因為在push的時候已經處理好了
        // 只要同時pop()就可以確保 minimumStack.top()會是dataStack裡面的最小元素
        dataStack.pop();
        minmumStack.pop();
    }

    int top() {
        return dataStack.top();
    }

    int getMin() {
        return minmumStack.top();
    }

   private:
    stack<int> dataStack, minmumStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(int argc, char const *argv[]) {
    stack<int> test;

    return 0;
}

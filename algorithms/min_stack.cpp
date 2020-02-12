// 155. Min Stack: https://leetcode.com/problems/min-stack
// Author: xianfeng.zhu@gmail.com

#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include <algorithm>

class MinStack
{
    struct Node
    {
        int val;
        int min;
        Node* next;
        Node(int _val, int _min, Node* _next = nullptr):
            val(_val), min(_min), next(_next) { }
    };

public:
    /** initialize your data structure here. */
    MinStack(): head_(nullptr), min_(INT_MAX)
    {
    }
    
    void push(int x)
    {
        min_ = std::min(x, min_);
        head_ = new Node(x, min_, head_);
    }
    
    void pop()
    {
        auto* ptr = head_;
        head_ = head_->next;
        min_ = ((head_ != nullptr) ? head_->min : INT_MAX);
        delete ptr;
    }
    
    int top()
    {
        return head_->val;
    }
    
    int getMin()
    {
        return head_->min;
    }

private:
    Node* head_;
    int min_;
};

int main(int argc, char* argv[])
{

    MinStack min_stack;
    min_stack.push(-2);
    min_stack.push(0);
    min_stack.push(-3);
    assert(min_stack.getMin() == -3);
    min_stack.pop();
    assert(min_stack.top() == 0);
    assert(min_stack.getMin() == -2);
    return 0;
}

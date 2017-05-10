#!/usr/bin/env python
# encoding: utf8

# Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
#     push(x) -- Push element x onto stack.
#     pop() -- Removes the element on top of the stack.
#     top() -- Get the top element.
#     getMin() -- Retrieve the minimum element in the stack.

__author__ = "Zhu Xianfeng <xianfeng.zhu@gmail.com>"

class MinStack:
    def __init__(self):
        self.stack = []
        self.mins  = []

    # @param x, an integer
    # @return an integer
    def push(self, x):
        self.stack.append(x)
        if len(self.mins) == 0:
            self.mins.append(x)
        elif self.mins[-1] >= x:
            self.mins.append(x)
        else:
            # minx = self.mins[-1]
            # self.mins.append(minx)
            pass
        return x

    # @return nothing
    def pop(self):
        if self.stack[-1] == self.mins[-1]:
            del self.mins[-1:]
        del self.stack[-1:]

    # @return an integer
    def top(self):
        return self.stack[-1]

    # @return an integer
    def getMin(self):
        return self.mins[-1]

def main():
    stack = MinStack()
    for i in range(10000):
        stack.push(i)
    stack.pop()
    print stack.getMin()


if __name__ == "__main__":
    main()

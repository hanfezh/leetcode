// 430. Flatten a Multilevel Doubly Linked List
// Author: xianfeng.zhu@gmail.com

#include <assert.h>

// Definition for a Node.
struct Node
{
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int v): val(v), prev(nullptr), next(nullptr), child(nullptr) { }
};

// Recursive
class Solution
{
public:
    Node* flatten(Node* head)
    {
        if (head == nullptr)
        {
            return head;
        }

        Node* tail = nullptr;
        return flatten(head, &tail);
    }

private:
    Node* flatten(Node* head, Node** tail)
    {
        Node* ptr = head;
        while (ptr->next != nullptr || ptr->child != nullptr)
        {
            if (ptr->child != nullptr)
            {
                Node* follow = ptr->next;
                ptr->next = flatten(ptr->child, tail);
                ptr->next->prev = ptr;
                ptr->child = nullptr;
                ptr = *tail;
                if (follow != nullptr)
                {
                    (*tail)->next = follow;
                    follow->prev = *tail;
                }
            }
            if (ptr->next != nullptr)
            {
                ptr = ptr->next;
            }
        }

        *tail = ptr;
        return head;
    }
};

int main(int argc, char* argv[])
{
    Node* head = nullptr;
    head = Solution().flatten(head);
    assert(head == nullptr);
    return 0;
}

// 707. Design Linked List
// Author: xianfeng.zhu@gmail.com

#include <assert.h>

struct LinkedNode
{
    int val;
    struct LinkedNode* next = nullptr;

    LinkedNode(int val_): val(val_) { }
};

class MyLinkedList
{
public:
    /** Initialize your data structure here. */
    MyLinkedList() = default;

    virtual ~MyLinkedList()
    {
        LinkedNode* ptr = head_;
        while (ptr != nullptr)
        {
            head_ = ptr->next;
            delete ptr;
            ptr = head_;
        }

        head_ = nullptr;
        tail_ = nullptr;
        size_ = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        if (index >= size_ || index < 0)
        {
            return -1;
        }

        auto* ptr = head_;
        while (index != 0)
        {
            index--;
            ptr = ptr->next;
        }

        return ptr->val;
    }
    
    /**
     * Add a node of value val before the first element of the linked list. 
     * After the insertion, the new node will be the first node of the linked list.
     */
    void addAtHead(int val)
    {
        LinkedNode* ptr = new LinkedNode(val);
        ptr->next = head_;
        head_ = ptr;
        if (tail_ == nullptr)
        {
            tail_ = ptr;
        }

        size_++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        LinkedNode* ptr = new LinkedNode(val);
        if (tail_ != nullptr)
        {
            tail_->next = ptr;
            tail_ = ptr;
        }
        else
        {
            head_ = ptr;
            tail_ = ptr;
        }

        size_++;
    }
    
    /**
     * Add a node of value val before the index-th node in the linked list. 
     * If index equals to the length of linked list, the node will be appended 
     * to the end of linked list. If index is greater than the length, the node 
     * will not be inserted.
     */
    void addAtIndex(int index, int val)
    {
        if (index > size_ || index < 0)
        {
            // Not inserted
            return;
        }

        LinkedNode* prev = nullptr;
        LinkedNode* ptr = head_;
        while (index != 0)
        {
            prev = ptr;
            ptr = ptr->next;
            index--;
        }

        // Create new node
        LinkedNode* node = new LinkedNode(val);
        node->next = ptr;

        if (prev == nullptr)
        {
            // Insert at head
            head_ = node;
        }
        else
        {
            // Linked previous
            prev->next = node;
        }
        if (ptr == nullptr)
        {
            // Insert at tail
            tail_ = node;
        }

        size_++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= size_)
        {
            // Invalid index
            return;
        }

        LinkedNode* prev = nullptr;
        LinkedNode* ptr = head_;
        while (index != 0)
        {
            prev = ptr;
            ptr = ptr->next;
            index--;
        }

        if (prev == nullptr)
        {
            // Delete head
            head_ = ptr->next;
            delete ptr;
        }
        else
        {
            prev->next = ptr->next;
            delete ptr;
        }
        if (ptr == tail_)
        {
            // Delete tail
            tail_ = prev;
        }

        size_--;
    }

private:
    LinkedNode* head_ = nullptr;
    LinkedNode* tail_ = nullptr;
    int size_ = 0;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
int main(int argc, char* argv[])
{
    MyLinkedList linkedList;
    linkedList.addAtHead(1);
    linkedList.addAtTail(3);
    linkedList.addAtIndex(1, 2);  // linked list becomes 1->2->3
    int val = linkedList.get(1);  // returns 2
    assert(val == 2);
    linkedList.deleteAtIndex(1);  // now the linked list is 1->3
    val = linkedList.get(1);      // returns 3
    assert(val == 3);
    return 0;
}

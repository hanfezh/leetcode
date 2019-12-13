// 234. Palindrome Linked List
// Author: xianfengzhu@gmail.com

#include <stdio.h>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) { }
};

// Recursive
class Solution
{
public:
    bool isPalindrome(ListNode* head)
    {
        return isPalindrome(&head, head);
    }

private:
    bool isPalindrome(ListNode** head, ListNode* tail)
    {
        if (tail == nullptr)
        {
            return true;
        }

        bool is_pal = isPalindrome(head, tail->next);
        if (!is_pal || (*head)->val != tail->val)
        {
            return false;
        }

        *head = (*head)->next;
        return true;
    }
};

int main(int argc, char* argv[])
{
    ListNode* head = nullptr;
    bool is_pal = Solution().isPalindrome(head);
    printf("Is palindrome? %s\n", (is_pal ? "Yes" : "No"));
    return 0;
}

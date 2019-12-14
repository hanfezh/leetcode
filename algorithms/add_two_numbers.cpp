// 2. Add Two Numbers: https://leetcode.com/problems/add-two-numbers
// Author: xianfengzhu@gmail.com

#include <assert.h>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) { }
};

// Iterative
class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode head(0);
        ListNode* ptr = &head;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr)
        {
            int val = carry;
            if (l1 != nullptr)
            {
                val += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                val += l2->val;
                l2 = l2->next;
            }
            carry = val / 10;
            val %= 10;
            ptr->next = new ListNode(val);
            ptr = ptr->next;
        }

        if (carry > 0)
        {
            ptr->next = new ListNode(carry);
        }

        return head.next;
    }
};

int main(int argc, char* argv[])
{
    ListNode* l1 = nullptr;
    ListNode* l2 = nullptr;
    ListNode* l3 = Solution().addTwoNumbers(l1, l2);
    assert(l3 == nullptr);
    return 0;
}

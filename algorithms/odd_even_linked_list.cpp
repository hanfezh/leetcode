// 328. Odd Even Linked List
// Author: xianfeng.zhu@gmail.com

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
    ListNode* oddEvenList(ListNode* head)
    {
        ListNode fake(0);
        ListNode* odd = &fake;
        ListNode* even = nullptr;
        ListNode* ptr = nullptr;
        int count = 0;

        while (head != nullptr)
        {
            count++;
            ptr = head;
            head = head->next;
            if (count & 0x1)
            {
                // Odd index
                ptr->next = odd->next;
                odd->next = ptr;
                odd = ptr;
            }
            else
            {
                // Even index
                ptr->next = nullptr;
                if (even == nullptr)
                {
                    even = ptr;
                    odd->next = even;
                }
                else
                {
                    even->next = ptr;
                    even = ptr;
                }
            }
        }

        return fake.next;
    }
};

int main(int argc, char* argv[])
{
    ListNode* head = nullptr;
    head = Solution().oddEvenList(head);
    return 0;
}

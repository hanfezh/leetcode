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
        if (head == nullptr)
        {
            return head;
        }

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* middle = even;

        while (even != nullptr && even->next != nullptr)
        {
            odd->next = even->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }

        odd->next = middle;
        return head;
    }
};

int main(int argc, char* argv[])
{
    ListNode* head = nullptr;
    head = Solution().oddEvenList(head);
    return 0;
}

#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *&head)
    {
        return helper(head, head);
    }

    ListNode *helper(ListNode *&head, ListNode *curr)
    {
        if (curr == nullptr || curr->next == nullptr)
            return curr;

        ListNode *prev = NULL;
        ListNode *pres = curr;
        ListNode *next = curr->next;

        while (pres)
        {
            pres->next = prev;
            prev = pres;
            pres = next;
            if (next)
                next = next->next;
        }

        head = prev;
        return head;
    }
};
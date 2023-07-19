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
private:
    ListNode *reverse(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *next = curr->next;

        while (curr)
        {
            curr->next = prev;
            prev = curr;
            curr = next;
            if (next)
                next = next->next;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL || !head->next)
            return true;

        ListNode *mid = head;
        ListNode *fast = head;
        ListNode *start = head;

        while (fast && fast->next)
        {

            mid = mid->next;
            fast = fast->next->next;
        }

        ListNode *head2 = reverse(mid);

        while (start && head2)
        {
            if (start->val != head2->val)
                break;

            else
            {
                start = start->next;
                head2 = head2->next;
            }
        }
        if (head2 == NULL)
            return true;
        else
            return false;
    }
};
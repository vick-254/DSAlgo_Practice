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
    ListNode *getMid(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode *reverse(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }

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
    void reorderList(ListNode *head)
    {
        if (!head || !head->next)
            return;

        ListNode *mid = getMid(head);
        ListNode *temp = new ListNode();

        ListNode *head2 = reverse(mid->next);
        mid->next = NULL;

        while (head && head2)
        {
            temp = head->next;
            head->next = head2;
            head = temp;

            temp = head2->next;
            head2->next = head;
            head2 = temp;
        }
        // if (head) head->next=NULL;
    }
};
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
    ListNode *getMid(ListNode *&head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *helper = new ListNode();

        while (fast && fast->next)
        {
            helper = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        helper->next = NULL;
        return slow;
    }

    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        ListNode *temp = new ListNode();
        ListNode *node = temp;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                temp->next = l1;
                temp = temp->next;
                l1 = l1->next;
            }
            else
            {
                temp->next = l2;
                temp = temp->next;
                l2 = l2->next;
            }
        }
        while (l1)
        {
            temp->next = l1;
            temp = temp->next;
            l1 = l1->next;
        }
        while (l2)
        {
            temp->next = l2;
            temp = temp->next;
            l2 = l2->next;
        }

        return node->next;
    }

public:
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *mid = getMid(head);

        ListNode *left = sortList(head);
        ListNode *right = sortList(mid);

        return merge(left, right);
    }
};
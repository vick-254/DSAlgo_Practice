#include <iostream>
using namespace std;

class ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {

        ListNode *head3 = new ListNode();
        ListNode *temp = head3;
        while (list1 && list2)
        {
            if (list1->val > list2->val)
            {
                temp->next = list2;
                temp = temp->next;
                list2 = list2->next;
            }
            else
            {
                temp->next = list1;
                temp = temp->next;
                list1 = list1->next;
            }
        }

        while (list1)
        {
            temp->next = list1;
            temp = temp->next;
            list1 = list1->next;
        }

        while (list2)
        {
            temp->next = list2;
            temp = temp->next;
            list2 = list2->next;
        }

        return head3->next;
    }
};

int main()
{
}
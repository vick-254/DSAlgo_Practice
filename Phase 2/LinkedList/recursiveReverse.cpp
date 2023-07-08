#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

public:
    ListNode(int val, ListNode *next)
    {
        this->val = val;
        this->next = next;
    }

public:
    void reverseRec(ListNode *&head, ListNode *node)
    {
        ListNode *temp = node;
        if (temp->next == nullptr)
        {
            head = temp;
            return;
        }
        reverseRec(head, temp->next);
        temp->next->next = temp;
        temp->next = NULL;
    }
    void print(ListNode *head)
    {
        ListNode *temp = head;
        while (temp != NULL)
        {

            cout << temp->val << " ";
            temp = temp->next;
        }
    }
};

int main()
{
    ListNode *head1 = new ListNode(1, nullptr);

    ListNode *head2 = new ListNode(2, nullptr);
    head1->next = head2;

    ListNode *head3 = new ListNode(3, nullptr);
    head2->next = head3;

    ListNode *head4 = new ListNode(4, nullptr);
    head3->next = head4;

    ListNode *head5 = new ListNode(5, nullptr);
    head4->next = head5;

    ListNode *head6 = new ListNode(6, nullptr);
    head5->next = head6;

    ListNode *head7 = new ListNode(7, nullptr);
    head6->next = head7;

    ListNode *head8 = new ListNode(8, nullptr);
    head7->next = head8;

    head1->reverseRec(head1, head1);

    head1->print(head1);
}
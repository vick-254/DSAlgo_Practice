#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    static int size;
    ListNode *next;
    ListNode()
    {
        size++;
    }
    ListNode(int val)
    {
        this->val = val;
        size++;
    }
    ListNode(int val, ListNode *next)
    {
        this->val = val;
        this->next = next;
        size++;
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

    void deleteDuplicates(ListNode *curr)
    {
        if (curr == NULL)
        {
            return;
        }
        if (!curr->next)
        {
            return;
        }
        if (curr->val == curr->next->val && curr->next->next != NULL)
        {
            curr->next = curr->next->next;
            deleteDuplicates(curr);
            return;
        }
        if (curr->val == curr->next->val && curr->next->next == NULL)
        {

            curr->next = NULL;

            return;
        }

        deleteDuplicates(curr->next);
        return;
    }

public:
    void insertRec(int value, int index, ListNode *&head)
    {
        if (index > size)
        {
            cout << "Enter valid index" << endl;
            return;
        }

        head = insertRec1(value, index, head);
        size++;
    }

private:
    ListNode *insertRec1(int value, int index, ListNode *&curr)
    {
        if (index == 0)
        {
            ListNode *temp = new ListNode(value, curr);

            return temp;
        }

        curr->next = insertRec1(value, --index, curr->next);

        return curr;
    }
};

int ListNode::size = 0;

int main()
{

    ListNode *node = new ListNode(12, NULL);
    ListNode *node2 = new ListNode(23, NULL);
    node->next = node2;
    ListNode *head = node;

    node->insertRec(23, 2, head);
    node->insertRec(34, 3, head);
    node->insertRec(34, 4, head);
    node->insertRec(34, 5, head);
    node->insertRec(45, 6, head);
    node->insertRec(45, 7, head);
    node->insertRec(45, 8, head);

    node->deleteDuplicates(head);

    node->print(head);
}

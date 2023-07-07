#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node(int value, Node *next)
    {
        this->value = value;
        this->next = next;
    }

public:
    void lengthCycle(Node *head)
    {

        int ans = lengthCycle2(head);
        cout << ans << endl;
    }

private:
    int lengthCycle2(Node *head)
    {
        Node *slow = head;
        Node *fast = head;

        int count = 0;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow)
            {
                Node *temp = slow;

                do
                {
                    temp = temp->next;
                    count++;
                } while (temp != slow);

                break;
            }
        }
        return count;
    }
};

int main()
{

    Node *head1 = new Node(1, nullptr);

    Node *head2 = new Node(2, nullptr);
    head1->next = head2;

    Node *head3 = new Node(3, nullptr);
    head2->next = head3;

    Node *head4 = new Node(4, nullptr);
    head3->next = head4;

    Node *head5 = new Node(5, nullptr);
    head4->next = head5;

    Node *head6 = new Node(2, nullptr);
    head5->next = head6;

    Node *head7 = new Node(2, nullptr);
    head6->next = head7;

    Node *head8 = new Node(2, nullptr);
    head7->next = head8;

    head8->next = head3;

    head1->lengthCycle(head1);
}

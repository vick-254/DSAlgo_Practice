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
};

void print(Node *&head)
{
    Node *temp = head;
    do
    {
        cout << temp->value << " -> ";

        temp = temp->next;
    } while (temp != head);
}

void insertHead(Node *&head, int value)
{
    Node *node = new Node(value, NULL);

    if (head == NULL)
    {
        head = node;
        head->next = head;
        return;
    }

    if (head->next == head)
    {

        node->next = head;
        head->next = node;

        return;
    }

    Node *temp = head;

    while (true)
    {
        if (temp->next == head)
        {

            break;
        }
        temp = temp->next;
    }

    temp->next = node;
    node->next = head;
}

int main()
{

    // Node *node = new Node(5, NULL);
    // Node *head = node;
    // insertHead(head, 6);
    // insertHead(head, 7);
    // insertHead(head, 8);
    // print(head);

    Node *head = NULL;
    insertHead(head, 5);
    insertHead(head, 6);
    insertHead(head, 7);
    insertHead(head, 8);
    insertHead(head, 9);
    print(head);
}
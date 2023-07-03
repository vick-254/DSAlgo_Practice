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

void deleteNode(Node *&head, int position)
{

    if (head == NULL)
    {
        return;
    }

    if (head->next == head)
    {
        delete head;
        return;
    }

    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    temp->next = temp->next->next;
}

int main()
{

    Node *head = NULL;
    insertHead(head, 5);
    insertHead(head, 6);
    insertHead(head, 7);
    insertHead(head, 8);
    insertHead(head, 9);
    deleteNode(head, 3);
    print(head);
}
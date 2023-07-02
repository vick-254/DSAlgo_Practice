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

    ~Node()
    {
    }
};

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {

        cout << temp->value << " ";
        temp = temp->next;
    }
}

void insertHead(int value, Node *&head)
{
    Node *node = new Node(value, NULL);
    node->next = head;
    head = node;
}

void insertTail(int value, Node *&tail)
{
    Node *node = new Node(value, NULL);
    tail->next = node;
    tail = node;
}

void insertAtPosition(int position, int value, Node *&head, Node *&tail)
{
    // inserting at start
    if (position == 1)
    {
        insertHead(value, head);
        return;
    }
    Node *node = new Node(value, NULL);
    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // inserting at last
    if (temp->next == NULL)
    {
        temp->next = node;

        tail = node;

        return;
    }

    node->next = temp->next;
    temp->next = node;
}

void deleteNode(int position, Node *&head)
{
    if (position == 1)
    {
        Node *temp = head;
        head = temp->next;

        delete temp;
        return;
    }

    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    Node *prev = temp;
    temp = temp->next;
    prev->next = temp->next;
    delete temp;
}

int main()
{
    Node *node1 = new Node(23, NULL);

    Node *head = node1;
    Node *tail = node1;

    insertHead(22, head);

    insertHead(21, head);
    insertTail(28, tail);
    insertTail(30, tail);

    insertAtPosition(6, 26, head, tail);

    deleteNode(3, head);
    deleteNode(1, head);

    print(head);

    return 0;
}
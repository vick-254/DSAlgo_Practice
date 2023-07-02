#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node *prev;

    Node(int value, Node *next, Node *prev)
    {
        this->value = value;
        this->next = next;
        this->prev = prev;
    }

    Node(int value, Node *next)
    {
        this->value = value;
        this->next = next;
    }
};

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " -> ";

        temp = temp->next;
    }
    cout << "END " << endl;
}

void insertHead(Node *&head, int value)
{
    Node *node = new Node(value, NULL);
    if (head == NULL)
    {
        head = node;
    }

    node->next = head;
    head->prev = node;
    head = node;
}

void insertTail(Node *&head, int value)
{
    Node *node = new Node(value, NULL);
    if (head == NULL)
    {
        head = node;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = node;
    node->prev = temp;
}

void insertPosition(Node *&head, int value, int position)
{

    Node *node = new Node(value, NULL);
    Node *temp = head;
    if (head == NULL)
    {
        head = node;
        return;
    }
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    node->next = temp->next;
    node->prev = temp;
    temp->next = node;
    node->next->prev = node;
}

void deleteNode(Node *&head, int position)
{
    Node *temp = head;
    if (head == NULL)
    {
        return;
    }
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    temp->next = temp->next->next;
    temp->next->prev = temp;
}

int main()
{
    Node *node = new Node(1, NULL);
    Node *head = node;
    insertHead(head, 0);
    insertHead(head, 7);
    insertHead(head, 9);
    insertTail(head, 98);
    insertPosition(head, 20, 4);
    deleteNode(head, 5);
    print(head);
}
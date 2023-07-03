#include <iostream>
using namespace std;

class Node
{

public:
    int value;
    static int size;
    Node *next;

    Node(int value, Node *next)
    {
        this->value = value;
        this->next = next;

        size++;
    }

public:
    void insertRec(int value, int index, Node *&head)
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
    Node *insertRec1(int value, int index, Node *&curr)
    {
        if (index == 0)
        {
            Node *temp = new Node(value, curr);

            return temp;
        }

        curr->next = insertRec1(value, --index, curr->next);

        return curr;
    }

public:
    void print(Node *head)
    {
        Node *temp = head;
        while (temp != NULL)
        {

            cout << temp->value << " ";
            temp = temp->next;
        }
    }
};

int Node::size = 0;

int main()
{

    Node *node = new Node(12, NULL);
    Node *node2 = new Node(23, NULL);
    node->next = node2;
    Node *head = node;

    node->insertRec(29, 1, head);
    node->insertRec(99, 3, head);
    node->insertRec(99, 0, head);
    node->insertRec(69, 4, head);
    node->insertRec(77, 78, head);
    node->print(head);
}
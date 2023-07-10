#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *createBinary(Node *root)
{

    int data;
    cout << "Enter Data" << endl;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    root = new Node(data);
    cout << "enter the element to left of " << data << endl;
    root->left = createBinary(root->left);

    cout << "enter the element to right of " << data << endl;
    root->right = createBinary(root->right);

    return root;
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{

    Node *root = NULL;

    root = createBinary(root);

    inorder(root);

    preOrder(root);

    postOrder(root);
}

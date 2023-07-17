#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node *inOrderSuccessor(Node *root, Node *x)
{
    Node *successor = new Node(-1);
    inOrderSuccessorHelper(root, x, successor);
    return successor;
}
// returns the inorder successor of the Node x in BST (rooted at 'root')
void inOrderSuccessorHelper(Node *root, Node *x, Node *&successor)
{
    if (root == NULL)
        return;

    if (root->data <= x->data)
    {
        inOrderSuccessorHelper(root->right, x, successor);
    }

    else
    {
        successor = root;
        inOrderSuccessorHelper(root->left, x, successor);
    }
}
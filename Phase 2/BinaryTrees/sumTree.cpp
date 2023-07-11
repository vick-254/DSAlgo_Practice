#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

class Solution
{
private:
    pair<bool, int> helper(Node *root)
    {
        if (root == NULL)
        {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }
        if (root->left == NULL && root->right == NULL)
        {
            pair<bool, int> p = make_pair(true, root->data);
            return p;
        }

        pair<bool, int> leftAns = helper(root->left);
        pair<bool, int> rightAns = helper(root->right);

        bool op1 = leftAns.first;
        bool op2 = rightAns.first;
        bool op3 = root->data == leftAns.second + rightAns.second;

        pair<bool, int> ans;
        ans.second = leftAns.second + rightAns.second + root->data;

        if (op1 && op2 && op3)
        {
            ans.first = true;
            return ans;
        }
        else
        {
            ans.first = false;
            return ans;
        }
    }

public:
    bool isSumTree(Node *root)
    {
        return helper(root).first;
    }
};

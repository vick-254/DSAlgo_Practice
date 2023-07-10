#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

pair<int, int> helper(TreeNode *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = helper(root->left);
    pair<int, int> right = helper(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int, int> ans;

    ans.first = max(op1, max(op2, op3));
    ;
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

int diameterOfBinaryTree(TreeNode *root)
{
    pair<int, int> p = helper(root);
    return p.first - 1;
}
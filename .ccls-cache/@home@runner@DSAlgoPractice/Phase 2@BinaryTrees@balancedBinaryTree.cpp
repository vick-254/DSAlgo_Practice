#include <iostream>
#include <bits/stdc++.h>

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

int heightOfTree(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = heightOfTree(root->left);
    int right = heightOfTree(root->right);
    int ans = max(left, right) + 1;
    return ans;
}

bool isBalanced(TreeNode *root)
{
    if (root == NULL)
    {
        return true;
    }

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);
    bool length = abs(heightOfTree(root->left) - heightOfTree(root->right)) <= 1;

    if (left && right && length)
    {
        return true;
    }
    else
        return false;
}
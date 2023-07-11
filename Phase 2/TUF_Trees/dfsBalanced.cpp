#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

int heightOfTree(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = heightOfTree(root->left);
    if (left == -1)
        return -1;
    int right = heightOfTree(root->right);
    if (right == -1)
        return -1;

    if (abs(left - right) > 1)
        return -1;

    int ans = max(left, right) + 1;
    return ans;
}

bool isBalanced(TreeNode *root)
{
    return heightOfTree(root) != -1;
}
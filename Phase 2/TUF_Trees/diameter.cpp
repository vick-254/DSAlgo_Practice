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

int helper(TreeNode *root, int &diameter)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = helper(root->left, diameter);
    int right = helper(root->right, diameter);

    diameter = max(diameter, left + right);

    return max(left, right) + 1;
}

int diameterOfBinaryTree(TreeNode *root)
{
    int diameter = 0;
    helper(root, diameter);
    return diameter;
}
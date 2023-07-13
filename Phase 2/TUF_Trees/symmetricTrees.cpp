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

class Solution
{
private:
    bool helper(TreeNode *left, TreeNode *right)
    {
        if (left == NULL || right == NULL)
            return left == right;

        if (left->val != right->val)
        {
            return false;
        }

        return helper(left->left, right->right) && helper(left->right, right->left);
    }

public:
    bool isSymmetric(TreeNode *root)
    {

        return root == NULL || helper(root->left, root->right);
    }
};
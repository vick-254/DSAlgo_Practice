#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

bool hasPathSum(TreeNode *root, int targetSum)
{
    if (root == NULL)
    {
        return false;
    }
    if (!root->left && !root->right && targetSum == root->val)
    {
        return true;
    }
    if (!root->left && !root->right && targetSum != root->val)
    {
        return false;
    }

    bool left = hasPathSum(root->left, targetSum - root->val);
    bool right = hasPathSum(root->right, targetSum - root->val);
    bool ans = left || right;

    return ans;
}
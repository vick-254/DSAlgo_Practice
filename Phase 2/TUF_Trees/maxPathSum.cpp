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

int helper(TreeNode *root, int &maxi)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = max(0, helper(root->left, maxi));
    int right = max(0, helper(root->right, maxi));

    maxi = max(maxi, left + right + root->val);

    return root->val + max(left, right);
}

int maxPathSum(TreeNode *root)
{
    int maxi = INT_MIN;
    helper(root, maxi);
    return maxi;
}
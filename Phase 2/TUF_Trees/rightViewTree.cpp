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
    void helper(TreeNode *node, int level, vector<int> &ans)
    {
        if (node == NULL)
            return;
        if (level == ans.size())
        {
            ans.push_back(node->val);
        }
        helper(node->right, level + 1, ans);
        helper(node->left, level + 1, ans);
    }

public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        helper(root, 0, ans);
        return ans;
    }
};
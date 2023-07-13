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
    void helper(TreeNode *root, string str, vector<string> &ans)
    {
        if (root == NULL)
        {
            return;
        }

        str += to_string(root->val) + "->";

        if (!root->left && !root->right)
        {
            str.pop_back();
            str.pop_back();
            ans.push_back(str);
            return;
        }

        helper(root->left, str, ans);
        helper(root->right, str, ans);

        str.pop_back();
        str.pop_back();
        str.pop_back();
    }

public:
    vector<string> binaryTreePaths(TreeNode *root)
    {

        vector<string> ans;
        helper(root, "", ans);
        return ans;
    }
};
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
            ans.push_back(node->val);

        // if(level=ans.size() && !node->left && !node->right){

        // }

        helper(node->left, level + 1, ans);
        helper(node->right, level + 1, ans);
    }

public:
    int findBottomLeftValue(TreeNode *root)
    {
        vector<int> ans;

        helper(root, 0, ans);
        int index = ans.size() - 1;
        return ans[index];
    }
};
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

vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    stack<TreeNode *> st1;
    stack<TreeNode *> st2;

    st1.push(root);

    while (!st1.empty())
    {
        TreeNode *top = st1.top();
        st1.pop();

        st2.push(top);

        if (top->left)
            st1.push(top->left);
        if (top->right)
            st1.push(top->right);
    }
    int size = st2.size();
    for (int i = 0; i < size; i++)
    {
        ans.push_back(st2.top()->val);
        st2.pop();
    }
    return ans;
}
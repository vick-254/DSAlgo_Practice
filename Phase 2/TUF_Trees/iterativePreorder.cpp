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

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    stack<TreeNode *> st;
    st.push(root);

    while (!st.empty())
    {
        TreeNode *top = st.top();
        st.pop();
        ans.push_back(top->val);
        if (top->right)
            st.push(top->right);
        if (top->left)
            st.push(top->left);
    }
    return ans;
}
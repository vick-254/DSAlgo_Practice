#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Solution
{
private:
    bool isLeaf(Node *root)
    {
        if (!root->left && !root->right)
        {
            return true;
        }
        else
            return false;
    }

    void addLeftBoundary(Node *root, vector<int> &ans)
    {

        Node *cur = root->left;
        while (cur)
        {
            if (!isLeaf(cur))
                ans.push_back(cur->data);
            if (cur->left)
                cur = cur->left;
            else
                cur = cur->right;
        }
    }

    void addLeafNodes(Node *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        if (isLeaf(root))
        {
            ans.push_back(root->data);
            return;
        }
        addLeafNodes(root->left, ans);
        addLeafNodes(root->right, ans);
    }

    void addRightBoundary(Node *root, vector<int> &ans)
    {
        Node *cur = root->right;
        stack<int> st;
        while (cur)
        {
            if (!isLeaf(cur))
                st.push(cur->data);
            if (cur->right)
                cur = cur->right;
            else
                cur = cur->left;
        }
        int size = st.size();
        for (int i = 0; i < size; i++)
        {
            ans.push_back(st.top());
            st.pop();
        }
    }

public:
    vector<int> boundary(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }

        if (!isLeaf(root))
            ans.push_back(root->data);
        addLeftBoundary(root, ans);
        addLeafNodes(root, ans);
        addRightBoundary(root, ans);

        return ans;
    }
};